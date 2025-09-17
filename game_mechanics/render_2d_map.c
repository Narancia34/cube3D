/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:29:11 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/21 18:35:26 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_img(t_cub3d *game, int xpos, int ypos, char c)
{
	if (c == '0' || ft_strchr("NEWS", c))
		mlx_image_to_window(game->mlx, game->tex.img1, xpos, ypos);
	else if (c == '1')
		mlx_image_to_window(game->mlx, game->tex.img2, xpos, ypos);
}

void	render_2d_map(void *param)
{
	int	i;
	int	j;
	t_cub3d *game;

	game = (t_cub3d *)param;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_img(game, j * 5, i * 5, game->map[i][j]);
			j++;
		}
		i++;
	}
	// render player
	mlx_image_to_window(game->mlx, game->tex.player,
			game->pxp * 5 + 2, game->pyp * 5 + 2);
	// game->tmp = 8;
}

