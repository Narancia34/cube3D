/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:38:32 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/01 09:50:07 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_textures(t_cub3d *game)
{

	mlx_texture_t* texture1 = mlx_load_png("./textures/Black.png");
	mlx_texture_t* texture2 = mlx_load_png("./textures/white.png");
	mlx_texture_t	*player = mlx_load_png("./textures/player_2.png");
	mlx_texture_t	*texture3 = mlx_load_png("./textures/wolftex/pics/greystone.png");
	mlx_texture_t	*texture4 = mlx_load_png("./textures/wolftex/pics/bluestone.png");
	mlx_texture_t	*texture5 = mlx_load_png("./textures/wolftex/pics/eagle.png");
	mlx_texture_t	*texture6 = mlx_load_png("./textures/wolftex/pics/mossy.png");
	mlx_texture_t	*texture7 = mlx_load_png("./textures/wolftex/pics/wood.png");

	if (!texture1 || !texture2 || !player)
		return(printf("error loading textures\n"), 1);
	game->tex.img1 = mlx_texture_to_image(game->mlx, texture1);
	game->tex.img2 = mlx_texture_to_image(game->mlx, texture2);
	game->tex.player = mlx_texture_to_image(game->mlx, player);
	game->tex.img3 = mlx_texture_to_image(game->mlx, texture3);
	game->tex.img4 = mlx_texture_to_image(game->mlx, texture4);
	game->tex.img5 = mlx_texture_to_image(game->mlx, texture5);
	game->tex.img6 = mlx_texture_to_image(game->mlx, texture6);
	game->tex.img7 = mlx_texture_to_image(game->mlx, texture7);
	if (NULL == game->tex.img1 || NULL == game->tex.img2 || NULL == game->tex.player)
		return(printf("error transforming textures ti images\n"), 1);
	mlx_resize_image(game->tex.img1, 4, 4);
	mlx_resize_image(game->tex.img2, 4, 4);
	mlx_resize_image(game->tex.player, 2, 2);
	return (0);
}
