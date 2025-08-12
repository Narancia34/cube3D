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

void	destroy_parcing(t_cub3d *game)
{
	if (NULL == game)
		exit(1);
	mlx_delete_image(game->mlx, game->parse.north_texture);
	mlx_delete_image(game->mlx, game->parse.south_texture);
	mlx_delete_image(game->mlx, game->parse.west_texture);
	mlx_delete_image(game->mlx, game->parse.east_texture);
	free_arr(game->parse.map);
	mlx_terminate(game->mlx);
	exit(1);
}
