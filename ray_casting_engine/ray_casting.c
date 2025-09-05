/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:28:51 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/03 14:28:53 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdint.h>

static int	is_wall(t_cub3d *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->parse->rows)
		return (1);
	if (!game->parse->map[y] || x >= (int)strlen(game->parse->map[y]))
		return (1);
	return (game->parse->map[y][x] == '1');
}

void init_ray(t_cub3d *game, double ray_angle)
{
    game->ray.ray_dir_x = cos(ray_angle);
    game->ray.ray_dir_y = sin(ray_angle);
    game->ray.map_x = (int)game->pxp;
    game->ray.map_y = (int)game->pyp;
    game->ray.delta_dist_x = fabs(1.0 / game->ray.ray_dir_x);
    game->ray.delta_dist_y = fabs(1.0 / game->ray.ray_dir_y);
    game->ray.hit = 0;
}

void get_side_dist(t_cub3d *game)
{
    if (game->ray.ray_dir_x < 0)
    {
        game->ray.step_x = -1;
        game->ray.side_dist_x = (game->pxp - game->ray.map_x) * game->ray.delta_dist_x;
    }
    else
    {
        game->ray.step_x = 1;
        game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->pxp) * game->ray.delta_dist_x;
    }
    if (game->ray.ray_dir_y < 0)
    {
        game->ray.step_y = -1;
        game->ray.side_dist_y = (game->pyp - game->ray.map_y) * game->ray.delta_dist_y;
    }
    else
    {
        game->ray.step_y = 1;
        game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->pyp) * game->ray.delta_dist_y;
    }
}

void perform_dda(t_cub3d *game)
{
    while (game->ray.hit == 0)
    {
        if (game->ray.side_dist_x < game->ray.side_dist_y)
        {
            game->ray.side_dist_x += game->ray.delta_dist_x;
            game->ray.map_x += game->ray.step_x;
            game->ray.side = 0;
        }
        else
        {
            game->ray.side_dist_y += game->ray.delta_dist_y;
            game->ray.map_y += game->ray.step_y;
            game->ray.side = 1;
        }
        if (is_wall(game, game->ray.map_x, game->ray.map_y))
            game->ray.hit = 1;
    }
}

double cast_single_ray(t_cub3d *game, double ray_angle)
{
    init_ray(game, ray_angle);
    get_side_dist(game);
    perform_dda(game);
    if (game->ray.side == 0)
        game->ray.perp_wall_dist = game->ray.side_dist_x - game->ray.delta_dist_x;
    else
        game->ray.perp_wall_dist = game->ray.side_dist_y - game->ray.delta_dist_y;
    return (game->ray.perp_wall_dist);
}
void calculate_wall_height(t_cub3d *game)
{
    game->ray.wall_height = (int)(HEIGHT / game->ray.perp_wall_dist);
    game->ray.wall_start = (HEIGHT - game->ray.wall_height) / 2;
    game->ray.wall_end = game->ray.wall_start + game->ray.wall_height;
}
void draw_wall_line(t_cub3d *game, int x)
{
	int y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;

	ceiling_color = (game->parse->ceiling_color[0] << 24) | 
		(game->parse->ceiling_color[1] << 16) | 
		(game->parse->ceiling_color[2] << 8) | 0xFF;
	floor_color = (game->parse->floor_color[0] << 24) | 
		(game->parse->floor_color[1] << 16) | 
		(game->parse->floor_color[2] << 8) | 0xFF;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < game->ray.wall_start)
			mlx_put_pixel(game->scene_image, x, y, ceiling_color);
		else if (y > game->ray.wall_end)
			mlx_put_pixel(game->scene_image, x, y, floor_color);
		y++;
	}
}


uint32_t get_pixel(mlx_image_t* tex, int x, int y) {
    uint8_t* px = tex->pixels + (y * tex->width + x) * 4; // 4 bytes: RGBA
    return *(uint32_t*)px; // packed 0xAABBGGRR
}

void put_pixel(mlx_image_t* img, int x, int y, uint32_t color) {
    if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
        return; // prevent segfault
    uint8_t* dst = img->pixels + (y * img->width + x) * 4;
    *(uint32_t*)dst = color;
}

void	texture_mapping(t_cub3d *game, int x)
{
	double	wallx;
	double	step;
	double	text_pos;
	int	tex_x;
	int	tex_y;
    mlx_image_t *texture;

	if (game->ray.side == 0)
		wallx = game->pyp + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wallx = game->pxp + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wallx -= floor(wallx);
	tex_x = (int)(wallx * 64);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		tex_x = 64 - tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		tex_x = 64 - tex_x - 1;
	step = 1.0 * 64 / game->ray.wall_height;
	text_pos = (game->ray.wall_start - HEIGHT / 2 + game->ray.wall_height / 2) * step;
	for (int y = game->ray.wall_start; y < game->ray.wall_end; y++)
	{
		tex_y = (int)text_pos & (63);
		text_pos += step;
        if (game->ray.side == 1 && game->ray.step_y == -1)
            texture = game->img3;
        else if (game->ray.side == 1 && game->ray.step_y == 1)
            texture = game->img4;
        else if (game->ray.side == 0 && game->ray.step_x == -1)
            texture = game->img5;
        else if (game->ray.side == 0 && game->ray.step_x == 1)
            texture = game->img6;
		uint32_t color = get_pixel(texture, tex_x, tex_y);
		put_pixel(game->scene_image, x, y, color);
	}
}

void    cast_rays(t_cub3d *game)
{
    int x;
    double ray_angle;

    x = 0;
    while (x < WIDTH)
    {
        ray_angle = game->player_angle - (FOV / 2) + ((double)x / WIDTH) * FOV;
        cast_single_ray(game, ray_angle);
        game->ray.perp_wall_dist *= cos(ray_angle - game->player_angle);
        calculate_wall_height(game);
        draw_wall_line(game, x);
	texture_mapping(game, x);
        x++;
    }
}
