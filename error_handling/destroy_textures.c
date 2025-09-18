/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:23:27 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 21:25:54 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	destroy_gun_frames(t_cub3d *game)
{
	int	index;

	index = 0;
	while (index < 15)
	{
		mlx_delete_image(game->mlx, game->textures.gun_frames[index]);
		index++;
	}
}

void	destroy_game(t_cub3d *game, int exit_status)
{
	if (NULL == game)
		exit(1);
	mlx_delete_image(game->mlx, game->textures.north_texture);
	mlx_delete_image(game->mlx, game->textures.south_texture);
	mlx_delete_image(game->mlx, game->textures.west_texture);
	mlx_delete_image(game->mlx, game->textures.east_texture);
	mlx_delete_image(game->mlx, game->textures.mini_map);
	mlx_delete_image(game->mlx, game->ray.texture);
	destroy_gun_frames(game);
	free_arr(game->map);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	// free(game->parse);
	exit(exit_status);
}
