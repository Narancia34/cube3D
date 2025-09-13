/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:55:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/04 16:14:20 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_new_position(double *new_x, double *new_y, t_cub3d *game)
{
	const double mouvment_speed = 3.0;
	double dir_x = cos(game->player_angle);
	double dir_y = sin(game->player_angle);

	if (game->mechanics->move_forward)
	{
		(*new_x) += dir_x * mouvment_speed * game->mlx->delta_time;
		(*new_y) += dir_y * mouvment_speed * game->mlx->delta_time;
	}
	if (game->mechanics->move_backward)
	{
		(*new_x) -= dir_x * mouvment_speed * game->mlx->delta_time;
		(*new_y) -= dir_y * mouvment_speed * game->mlx->delta_time;
	}
	if (game->mechanics->move_right)
	{
		(*new_x) -= dir_y * mouvment_speed * game->mlx->delta_time;
		(*new_y) += dir_x * mouvment_speed * game->mlx->delta_time;
	}
	if (game->mechanics->move_left)
	{
		(*new_x) += dir_y * mouvment_speed * game->mlx->delta_time;
		(*new_y) -= dir_x * mouvment_speed * game->mlx->delta_time;
	}
}

void	player_mouvement(t_cub3d *game)
{
	double		new_x;
	double		new_y;
	double		check_x;
	double		check_y;

	new_x = game->pxp;
	new_y = game->pyp;
	player_new_position(&new_x, &new_y, game);
	// Check collision for the X-axis
	check_x = new_x;
	if (new_x > game->pxp)
		check_x += 0.5;
	else if (new_x < game->pxp)
		check_x -= 0.5;
	if ('1' != game->parse->map[(int)floor(game->pyp)][(int)floor(check_x)] && 'D' != game->parse->map[(int)floor(game->pyp)][(int)floor(check_x)])
		game->pxp = new_x;
	// Check collision for the Y-axis, using the NEWLY updated player x_pos
	check_y = new_y;
	if (new_y > game->pyp)
		check_y += 0.5;
	else if (new_y < game->pyp)
		check_y -= 0.5;
	if ('1' != game->parse->map[(int)floor(check_y)][(int)floor(game->pxp)] && 'D' != game->parse->map[(int)floor(check_y)][(int)floor(game->pxp)])
		game->pyp = new_y;
	// printf(YELLOW"x pos -- %f\n", game->pxp);
	// printf(BLUE"y pos -- %f\n", game->pyp);
	game->tex.player->instances[0].y = (int32_t)(game->pyp * 5 + 2);
	game->tex.player->instances[0].x = (int32_t)(game->pxp * 5 + 2);
}


