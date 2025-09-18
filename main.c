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

static void	init_game(t_cub3d *game, int ac)
{
	mlx_texture_t	*texture;

	(void)ac;
	game->map = NULL;
	game->textures.north_texture = NULL;
	game->textures.south_texture = NULL;
	game->textures.east_texture = NULL;
	game->textures.west_texture = NULL;
	game->mechanics.move_forward = false;
	game->mechanics.move_backward = false;
	game->mechanics.move_left = false;
	game->mechanics.move_right = false;
	game->mechanics.pause_game = false;
	game->mechanics.look_right = false;
	game->mechanics.look_left = false;
	game->attack_animation = false;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	game->textures.mini_map = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->ray.texture = NULL;

	// WARN: destroy door images
	texture = mlx_load_png("./textures/door.png");
	game->textures.door = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/door_sides.png");
	game->textures.door_side = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	close_game(void *param)
{
	destroy_game((t_cub3d *)param, 0);
}

// static void

int main(int ac, char **av)
{
	t_cub3d	game;
	
	init_game(&game, ac);
	parse_file(av, &game);
	mlx_image_to_window(game.mlx, game.textures.mini_map, 0, 0);
	load_gun_frames(&game);
	init_gun_frames(&game);
	mlx_key_hook(game.mlx, key_handler, &game);
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_DISABLED);
	mlx_cursor_hook(game.mlx, cursor_handler, &game);
	mlx_mouse_hook(game.mlx, mouse_click_handler, &game);
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
}
