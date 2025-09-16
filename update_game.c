/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:23:49 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/16 21:39:47 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_game(void *param)
{
	t_cub3d *game = (t_cub3d *)param;

	player_rotation(game);
	player_mouvement(game);
	cast_rays(game);
	render_mini_map(game);
	update_gun_animation(game);
}
