/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:55:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/01 10:36:49 by fbicane          ###   ########.fr       */
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
	if (game->mechanics->move_left)
	{
		(*new_x) += dir_y * mouvment_speed * game->mlx->delta_time;
		(*new_y) += dir_x * mouvment_speed * game->mlx->delta_time;
	}
	if (game->mechanics->move_right)
	{
		(*new_x) -= dir_y * mouvment_speed * game->mlx->delta_time;
		(*new_y) -= dir_x * mouvment_speed * game->mlx->delta_time;
	}
}

void	player_mouvement(t_cub3d *game)
{
	double	new_x = game->pxp;
	double	new_y = game->pyp;

	player_new_position(&new_x, &new_y, game);
	game->pyp = new_y;
	game->pxp = new_x;
	game->mechanics->player->instances[0].y = (int32_t)(game->pyp * 5 + 2);
	game->mechanics->player->instances[0].x = (int32_t)(game->pxp * 5 + 2);
}
