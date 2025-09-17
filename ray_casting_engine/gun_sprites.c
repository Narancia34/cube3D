/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:27:38 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/15 18:33:09 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	load_gun_frames_utils(t_cub3d *game, mlx_texture_t *gun)
{
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_8.png");
	game->textures.gun_frames[7] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_9.png");
	game->textures.gun_frames[8] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_10.png");
	game->textures.gun_frames[9] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_11.png");
	game->textures.gun_frames[10] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_12.png");
	game->textures.gun_frames[11] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_13.png");
	game->textures.gun_frames[12] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_14.png");
	game->textures.gun_frames[13] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_15.png");
	game->textures.gun_frames[14] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
}

void	load_gun_frames(t_cub3d *game)
{
	mlx_texture_t *gun;

	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_1.png");
	game->textures.gun_frames[0] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_2.png");
	game->textures.gun_frames[1] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_3.png");
	game->textures.gun_frames[2] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_4.png");
	game->textures.gun_frames[3] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_5.png");
	game->textures.gun_frames[4] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_6.png");
	game->textures.gun_frames[5] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	gun = mlx_load_png("./textures/shitgun_animation/shitgun_animation_7.png");
	game->textures.gun_frames[6] = mlx_texture_to_image(game->mlx, gun);
	mlx_delete_texture(gun);
	load_gun_frames_utils(game, gun);
}

void	init_gun_frames(t_cub3d *game)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		mlx_image_to_window(game->mlx, game->textures.gun_frames[i], 600, 325);
		game->textures.gun_frames[i]->instances[0].z = 1;
		game->textures.gun_frames[i]->instances[0].enabled = false;
		i++;
	}
	game->textures.gun_frames[0]->instances[0].enabled = true;
}

void	update_gun_animation(t_cub3d *game)
{
	if (!game->attack_animation)
		return ;
	game->anim_timer += game->mlx->delta_time;
	if (!(game->anim_timer >= 1 / 12.0))
		return ;
	game->anim_timer -= 1 / 12.0;
	game->textures.gun_frames[game->gun_frame]->instances[0].enabled = false;
	game->gun_frame++;
	if (game->gun_frame < 15)
		game->textures.gun_frames[game->gun_frame]->instances[0].enabled = true;
	else
	{
		game->attack_animation = false;
		game->textures.gun_frames[0]->instances[0].enabled = true;
	}
}

void	play_gun_animation(t_cub3d *game)
{
	if (game->attack_animation)
		return ;
	game->attack_animation = true;
	game->gun_frame = 0;
	game->anim_timer = 0.0;
	game->textures.gun_frames[0]->instances[0].enabled = false;
}
