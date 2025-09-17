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

void	destroy_parsing(t_cub3d *game)
{
	if (NULL == game)
		exit(1);
	mlx_delete_image(game->mlx, game->textures.north_texture);
	mlx_delete_image(game->mlx, game->textures.south_texture);
	mlx_delete_image(game->mlx, game->textures.west_texture);
	mlx_delete_image(game->mlx, game->textures.east_texture);
	mlx_delete_image(game->mlx, game->textures.mini_map);

	// WARN: mlx_delete_image on gun frames array

	free_arr(game->map);
	mlx_terminate(game->mlx);
	mlx_close_window(game->mlx);
	// free(game->parse);
	exit(1);
}
