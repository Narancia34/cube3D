/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:28:51 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/17 17:37:18 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdint.h>

static int	is_wall(t_cub3d *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->parse.rows)
		return (1);
	if (!game->map[y] || x >= (int)strlen(game->map[y]))
		return (1);
	if (game->map[y][x] == 'D')
		game->ray.is_door = 1;
	return (game->map[y][x] == '1' || game->map[y][x] == 'D');
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
	game->ray.is_door = 0;
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


void    cast_rays(t_cub3d *game)
{
    int x;
    double ray_angle;

    x = 0;
    while (x < WIDTH)
    {
        ray_angle = game->player_angle - (FOV / 2) + ((double)x / WIDTH) * FOV;
        cast_single_ray(game, ray_angle);
        texture_mapping(game, x);
        game->ray.perp_wall_dist *= cos(ray_angle - game->player_angle);
        calculate_wall_height(game);
        draw_wall_line(game, x);
        x++;
    }
}
