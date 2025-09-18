/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:35:15 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/18 16:29:00 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_wall_line(t_cub3d *game, int x)
{
	int			y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;

	ceiling_color = (game->textures.ceiling_color[0] << 24)
		| (game->textures.ceiling_color[1] << 16)
		| (game->textures.ceiling_color[2] << 8) | 0xFF;
	floor_color = (game->textures.floor_color[0] << 24)
		| (game->textures.floor_color[1] << 16)
		| (game->textures.floor_color[2] << 8) | 0xFF;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < game->ray.wall_start)
			mlx_put_pixel(game->textures.mini_map, x, y, ceiling_color);
		else if (y > game->ray.wall_end)
			mlx_put_pixel(game->textures.mini_map, x, y, floor_color);
		y++;
	}
}

static uint32_t	get_pixel(mlx_image_t *tex, int x, int y)
{
	return (*((uint32_t *)(tex->pixels + (y * tex->width + x) * 4)));
}

static void	put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*dst;

	if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
		return ;
	dst = img->pixels + (y * img->width + x) * 4;
	*(uint32_t *)dst = color;
}

static void	init_calculation(t_cub3d *game)
{
	if (game->ray.side == 0)
		game->ray.wallx = game->pyp
			+ game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		game->ray.wallx = game->pxp
			+ game->ray.perp_wall_dist * game->ray.ray_dir_x;
	game->ray.wallx -= floor(game->ray.wallx);
	game->ray.tex_x = (int)(game->ray.wallx * 64);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		game->ray.tex_x = 64 - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		game->ray.tex_x = 64 - game->ray.tex_x - 1;
	game->ray.step = 1.0 * 64 / game->ray.wall_height;
	game->ray.text_pos = (game->ray.wall_start
			- HEIGHT / 2.0 + game->ray.wall_height / 2.0) * game->ray.step;
}

void	texture_mapping(t_cub3d *game, int x)
{
	int			y;
	uint32_t	color;

	init_calculation(game);
	y = game->ray.wall_start;
	while (y < game->ray.wall_end)
	{
		game->ray.tex_y = (int)game->ray.text_pos & (63);
		game->ray.text_pos += game->ray.step;
		if (game->ray.is_door == 1)
			game->ray.texture = game->textures.door;
		else
			render_non_doors(game);
		color = get_pixel(game->ray.texture, game->ray.tex_x, game->ray.tex_y);
		put_pixel(game->textures.mini_map, x, y, color);
		y++;
	}
}
