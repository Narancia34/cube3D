/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:55:04 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/18 17:07:36 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_new_position(double *new_x, double *new_y, t_cub3d *game)
{
	double	dir_x;
	double	dir_y;

	dir_x = cos(game->player_angle);
	dir_y = sin(game->player_angle);
	if (game->mechanics.move_forward)
	{
		(*new_x) += dir_x * 3.0 * game->mlx->delta_time;
		(*new_y) += dir_y * 3.0 * game->mlx->delta_time;
	}
	if (game->mechanics.move_backward)
	{
		(*new_x) -= dir_x * 3.0 * game->mlx->delta_time;
		(*new_y) -= dir_y * 3.0 * game->mlx->delta_time;
	}
	if (game->mechanics.move_right)
	{
		(*new_x) -= dir_y * 3.0 * game->mlx->delta_time;
		(*new_y) += dir_x * 3.0 * game->mlx->delta_time;
	}
	if (game->mechanics.move_left)
	{
		(*new_x) += dir_y * 3.0 * game->mlx->delta_time;
		(*new_y) -= dir_x * 3.0 * game->mlx->delta_time;
	}
}

static bool	is_obstacle(t_cub3d *game, int x, int y)
{
	char	c;

	if (y < 0 || x < 0
		|| y >= game->parse.rows
		|| x >= (int)ft_strlen(game->map[y]))
		return (true);
	c = game->map[y][x];
	return (c == '1' || c == 'D');
}

static bool	is_blocked(t_cub3d *game, double x, double y)
{
	double	radius;

	radius = 0.3;
	return (is_obstacle(game, (int)(x - radius), (int)(y - radius))
		|| is_obstacle(game, (int)(x + radius), (int)(y - radius))
		|| is_obstacle(game, (int)(x - radius), (int)(y + radius))
		|| is_obstacle(game, (int)(x + radius), (int)(y + radius)));
}

static void	update_position(t_cub3d *game, double new_x, double new_y)
{
	if (!is_blocked(game, new_x, game->pyp))
		game->pxp = new_x;
	if (!is_blocked(game, game->pxp, new_y))
		game->pyp = new_y;
}

void	player_mouvement(t_cub3d *game)
{
	double		new_x;
	double		new_y;

	new_x = game->pxp;
	new_y = game->pyp;
	player_new_position(&new_x, &new_y, game);
	update_position(game, new_x, new_y);
}
