/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:23:49 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/15 18:23:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_filled_square(mlx_image_t* image, int start_x, int start_y, int size, uint32_t color)
{
    int x;
    int y = start_y;

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

void draw_map_scene(t_cub3d *game)
{
	const int tile_size = 5;
	const uint32_t floor_color = 0xFFFFFFFF;
	const uint32_t wall_color = 0x000000FF;
	int i = 0;
	int j;

	while (game->parse->map[i])
	{
		j = 0;
		while (game->parse->map[i][j])
		{
			if (game->parse->map[i][j] == '1')
			{
				draw_filled_square(game->scene_image, j * tile_size, i * tile_size, tile_size, wall_color);
			}
			else
				draw_filled_square(game->scene_image, j * tile_size, i * tile_size, tile_size, floor_color);
			j++;
		}
		i++;
	}
}

void draw_line(mlx_image_t *image, int x1, int y1, int x2, int y2, uint32_t color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps;
	float x_inc;
	float y_inc;
	float x = x1;
	float y = y1;
	int i = 0;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	if (steps == 0)
		return;

	x_inc = (float)dx / (float)steps;
	y_inc = (float)dy / (float)steps;

	while (i <= steps)
	{
		if (x >= 0 && x < (int)image->width && y >= 0 && y < (int)image->height)
			mlx_put_pixel(image, (int)round(x), (int)round(y), color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void draw_player_pov(t_cub3d *game)
{
    const int line_length = 3;
    const uint32_t line_color = 0xFF0000FF; // Red

    int start_x = (int)(game->pxp * 5+2);
    int start_y = (int)(game->pyp * 5+2);

    double dir_x = cos(game->player_angle);
    double dir_y = sin(game->player_angle);
    int end_x = start_x + (line_length * dir_x);
    int end_y = start_y + (line_length * dir_y);

    if (game->scene_image)
    {
        draw_line(game->scene_image, start_x, start_y, end_x, end_y, line_color);
    }
}

void	update_game(void *param)
{
	t_cub3d *game = (t_cub3d *)param;

	player_rotation(game);
	player_mouvement(game);
	cast_rays(game);
	draw_map_scene(game);
	draw_player_pov(game);
	update_gun_animation(game);
}
