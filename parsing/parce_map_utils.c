/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:14:15 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/05 14:29:52 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**copy_map(t_cub3d *game)
{
	char	**map_copy;
	int		i;
	int		rows;

	rows = 0;
	while (game->parse->map[rows])
		rows++;
	game->parse->rows = rows;
	map_copy = malloc((rows + 1) * sizeof(char *));
	if (!map_copy)
		exit(0);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(game->parse->map[i]);
		if (!map_copy[i])
		{
			free_arr(map_copy);
			printf("error\n");
			exit(0);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_player_position(t_cub3d *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->parse->map[y])
	{
		x = 0;
		while (game->parse->map[y][x])
		{
			if (game->parse->map[y][x] == 'N'
				|| game->parse->map[y][x] == 'S'
				|| game->parse->map[y][x] == 'E'
				|| game->parse->map[y][x] == 'W')
			{
				game->parse->pxp = x;
				game->parse->pyp = y;
				game->pxp = x;
				game->pyp = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
