/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   install_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:57:23 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/19 21:53:08 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static void	close_game(void *param)
{
	destroy_game((t_cub3d *)param, 0);
}

static void	update_game(void *param)
{
	t_cub3d	*game;

	game = (t_cub3d *)param;
	player_rotation(game);
	player_mouvement(game);
	cast_rays(game);
	render_mini_map(game);
	update_gun_animation(game);
}

void	install_hooks(t_cub3d *game)
{
	mlx_key_hook(game->mlx, key_handler, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(game->mlx, cursor_handler, game);
	mlx_mouse_hook(game->mlx, mouse_click_handler, game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop_hook(game->mlx, update_game, game);
}
