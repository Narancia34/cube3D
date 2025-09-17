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
	if (game->mechanics.pause_game)
		return ;
	deltax = xpos - WIDTH / 2.0;
	sensitivity = 0.0005;
	game->player_angle += deltax * sensitivity;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}

void	mouse_click_handler(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_cub3d	*game;

	game = (t_cub3d *)param;
	(void)mods;
	if (MLX_MOUSE_BUTTON_LEFT == button && MLX_PRESS == action)
		play_gun_animation(game);
}
