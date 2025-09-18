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

void	init_game(t_cub3d *game, int ac)
{
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
	game->ray.texture = NULL;
	game->parse.floor_color = false;
	game->parse.ceiling_color = false;
}

void	init_textures(t_cub3d *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/door.png");
	game->textures.door = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/door_sides.png");
	game->textures.door_side = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->textures.mini_map = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->textures.mini_map, 0, 0);
	load_gun_frames(game);
	init_gun_frames(game);
}
