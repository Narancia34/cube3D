/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:38:32 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/21 15:24:15 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_textures(t_cub3d *game)
{

	mlx_texture_t* texture1 = mlx_load_png("./textures/Black.png");
	mlx_texture_t* texture2 = mlx_load_png("./textures/white.png");
	if (!texture1 || !texture2)
		return(printf("error11\n"), 1);
	game->mechanics->img1 = mlx_texture_to_image(game->mlx, texture1);
	game->mechanics->img2 = mlx_texture_to_image(game->mlx, texture2);
	if (!game->mechanics->img1 || !game->mechanics->img2)
		return(printf("error22\n"), 1);
	mlx_resize_image(game->mechanics->img1, 20, 20);
	mlx_resize_image(game->mechanics->img2, 20, 20);
	return (0);
}
