/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:38:32 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/21 20:35:09 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_textures(t_cub3d *game)
{

	mlx_texture_t* texture1 = mlx_load_png("./textures/Black.png");
	mlx_texture_t* texture2 = mlx_load_png("./textures/white.png");
	mlx_texture_t	*player = mlx_load_png("./textures/player_2.png");


	if (!texture1 || !texture2 || !player)
		return(printf("error loading textures\n"), 1);
	game->mechanics->img1 = mlx_texture_to_image(game->mlx, texture1);
	game->mechanics->img2 = mlx_texture_to_image(game->mlx, texture2);
	game->mechanics->player = mlx_texture_to_image(game->mlx, player);
	if (NULL == game->mechanics->img1 || NULL == game->mechanics->img2 || NULL == game->mechanics->player)
		return(printf("error transforming textures ti images\n"), 1);
	mlx_resize_image(game->mechanics->img1, 20, 20);
	mlx_resize_image(game->mechanics->img2, 20, 20);
	mlx_resize_image(game->mechanics->player, 4, 4);
	return (0);
}
