/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:23:49 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/31 10:16:33 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h> // Needed for cos(), sin(), abs(), and round()
#include <stdint.h>

// Forward declaration for your movement function, which should be in another file.
void player_mouvement(t_cub3d *game);

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

	// Avoid division by zero if start and end points are the same
	if (steps == 0)
		return;

	x_inc = (float)dx / (float)steps;
	y_inc = (float)dy / (float)steps;

	while (i <= steps)
	{
		if (x >= 0 && x < image->width && y >= 0 && y < image->height)
			mlx_put_pixel(image, (int)round(x), (int)round(y), color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	update_game(void *param)
{
	t_cub3d *game = (t_cub3d *)param;

	// --- 1. HANDLE ROTATION ---
	const double ROTATION_SPEED = 3.0; // Radians per second
	if (game->mechanics->look_right)
		game->player_angle += ROTATION_SPEED * game->mlx->delta_time;
	if (game->mechanics->look_left)
		game->player_angle -= ROTATION_SPEED * game->mlx->delta_time;
	double dir_x = cos(game->player_angle);
	double dir_y = sin(game->player_angle);
	double	new_x = game->pxp;
	double	new_y = game->pyp;
	if (game->mechanics->move_forward)
	{
		new_x += dir_x * 0.5 * game->mlx->delta_time;
		new_y += dir_y * 0.5 * game->mlx->delta_time;
	}
	if (game->mechanics->move_backward)
	{
		new_x -= dir_x * 0.5 * game->mlx->delta_time;
		new_y -= dir_y * 0.5 * game->mlx->delta_time;

	}
	if (game->mechanics->move_left)
	{
		new_x += dir_y * 0.5 * game->mlx->delta_time;
		new_y += dir_x * 0.5 * game->mlx->delta_time;

	}
	if (game->mechanics->move_right)
	{
		new_x -= dir_y * 0.5 * game->mlx->delta_time;
		new_y -= dir_x * 0.5 * game->mlx->delta_time;

	}
	game->pxp = new_x;
	game->pyp = new_y;

	// --- 2. HANDLE MOVEMENT & COLLISION ---
	// player_mouvement(game); // This calls your existing movement function

	// --- 3. DRAW THE SCENE FOR THE NEW FRAME ---

	// IMPORTANT: You must have a function to redraw your map here.
	// This erases the line from the last frame.
	// For example:
	// draw_the_map(game);

	// Calculate the start and end points for the POV line
	int start_x = (int)(game->pxp * 20 + 8);
	int start_y = (int)(game->pyp * 20 + 8);
	int line_length = 30;

	// Use the angle to find the direction

	int end_x = start_x + line_length * dir_x;
	int end_y = start_y + line_length * dir_y;

	// Draw the new POV line onto your main image/canvas
	// IMPORTANT: Replace `game->scene_image` with the actual mlx_image_t
	// you are using for your 2D map view.
	if (game->scene_image) // Check if image exists
		draw_line(game->scene_image, start_x, start_y, end_x, end_y, 0xFF0000FF);
	game->mechanics->player->instances[0].y = (int32_t)(game->pyp * 20 + 8);
	game->mechanics->player->instances[0].x = (int32_t)(game->pxp * 20 + 8);
}
