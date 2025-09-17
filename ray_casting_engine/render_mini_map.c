/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:24:26 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/16 21:45:22 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_square(mlx_image_t* image, int start_x, int start_y, uint32_t color)
{
	int x;
	int y = start_y;
	int	size;

	if (0xff0505FF == color)
		size = 3;
	else
		size = 5;
	while (y < start_y + size)
	{
		x = start_x;
		while (x < start_x + size)
		{
			if (x >= 0 && x < (int)image->width && y >= 0 && y < (int)image->height)
				mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

static void	render_tile(t_cub3d *game, int map_x, int map_y)
{
	int screen_x;
	int screen_y;

	screen_x = (map_x - ((int)game->pxp - 10)) * 5;
	screen_y = (map_y - ((int)game->pyp - 10)) * 5;
	if (map_y >= 0 && map_y < game->parse.rows && map_x >= 0
			&& map_x < (int)ft_strlen(game->map[map_y]))
	{
		if (game->map[map_y][map_x] == '1')
			render_square(game->textures.mini_map, screen_x, screen_y, 0x000000FF);
		else if (game->map[map_y][map_x] == 'D')
			render_square(game->textures.mini_map, screen_x, screen_y, 0xab9a6aFF);
		else
			render_square(game->textures.mini_map, screen_x, screen_y, 0xfafafaFF);
	}
	else
		render_square(game->textures.mini_map, screen_x, screen_y, 0xabababFF);
}

void render_mini_map(t_cub3d *game)
{
	int map_x;
	int map_y;

	map_y = (int)game->pyp - 10;
	const int max_y = (int)game->pyp + 10;
	const int max_x = (int)game->pxp + 10;

	while (map_y <= max_y)
	{
		map_x = (int)game->pxp - 10;
		while (map_x <= max_x)
		{
			render_tile(game, map_x, map_y);
			map_x++;
		}
		map_y++;
	}
	render_square(game->textures.mini_map, 10 * 5, 10 * 5, 0xff0505FF);
}
