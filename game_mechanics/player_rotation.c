/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:06:26 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/01 10:36:49 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_rotation(t_cub3d *game)
{
	const double rotation_speed = 2.0;

	if (game->mechanics.look_right)
		game->player_angle += rotation_speed * game->mlx->delta_time;
	if (game->mechanics.look_left)
		game->player_angle -= rotation_speed * game->mlx->delta_time;
}
