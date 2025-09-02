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
		mlx_image_to_window(game->mlx, game->mechanics->img1, xpos, ypos);
	else if (c == '1')
		mlx_image_to_window(game->mlx, game->mechanics->img2, xpos, ypos);
}

void	render_2d_map(void *param)
{
	int	i;
	int	j;
	t_cub3d *game;

	game = (t_cub3d *)param;
	i = 0;
	while (game->parse->map[i])
	{
		j = 0;
		while (game->parse->map[i][j])
		{
			put_img(game, j * 20, i * 20, game->parse->map[i][j]);
			j++;
		}
		i++;
	}
	// render player
	mlx_image_to_window(game->mlx, game->mechanics->player,
			game->pxp * 20 + 8, game->pyp * 20 + 8);
	// game->tmp = 8;
}

