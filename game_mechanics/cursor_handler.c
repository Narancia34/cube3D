/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:36:24 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/08 15:48:03 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cursor_handler(double xpos, double ypos, void *param)
{
	t_cub3d	*game;
	double	deltax;
	double	sensitivity;

	(void)ypos;
	game = (t_cub3d *)param;
	if (game->mechanics.ctrl_pressed)
		return ;
	deltax = xpos - WIDTH / 2.0;
	sensitivity = 0.005;
	game->player_angle += deltax * sensitivity;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}
