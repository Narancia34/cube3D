/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:06:26 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/31 10:20:07 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

static void	set_player_direction(t_cub3d *game)
{
	if ('N' == game->parse->player_direction)
		game->player_angle = -M_PI/2.0;
	else if ('S' == game->parse->player_direction)
		game->player_angle = M_PI / 2.0;
	else if ('W' == game->parse->player_direction)
		game->player_angle = M_PI;
	else if ('E' == game->parse->player_direction)
		game->player_angle = 0.0;
}

void	player_rotation(t_cub3d *game)
{
	set_player_direction(game);
}
