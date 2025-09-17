/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:33 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/16 16:53:04 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_cub3d *game)
{
	game->parse.file_name = NULL;
	game->map = NULL;
	game->textures.north_texture = NULL;
	game->textures.south_texture = NULL;
	game->textures.east_texture = NULL;
	game->textures.west_texture = NULL;
	// mouvment
	game->mechanics.move_forward = false;
	game->mechanics.move_backward = false;
	game->mechanics.move_left = false;
	game->mechanics.move_right = false;
	game->mechanics.pause_game = false;
	// rotation
	game->mechanics.look_right = false;
	game->mechanics.look_left = false;

	game->attack_animation = false;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	game->textures.mini_map = mlx_new_image(game->mlx, WIDTH, HEIGHT);
}

void	close_game(void *param)
{
	destroy_game((t_cub3d *)param, 0);
}

int main(int ac, char **av)
{
	(void)ac;
	t_cub3d	game;
	
	// ft_memset(&game, 0, sizeof(t_cub3d));
	// game.parse = malloc(sizeof(t_parse));
	// game.mechanics = malloc(sizeof(t_mechanics));
	init_game(&game);
	parse_file(av, &game);
	/*if (load_textures(&game) != 0)*/
	/*	destroy_parsing(&game);*/
	// render_2d_map(&game);
	mlx_image_to_window(game.mlx, game.textures.mini_map, 0, 0);
	// game.textures.mini_map->instances[0].z = 0;
	load_gun_frames(&game);
	init_gun_frames(&game);
	mlx_key_hook(game.mlx, key_handler, &game);
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(game.mlx, cursor_handler, &game);
	mlx_mouse_hook(game.mlx, mouse_click_handler, &game);
	// TODO: mlx_close_hook(); to close cleanly
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
	// destroy_game(&game, 0);
	return (0);
}
