/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:14:15 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/12 17:41:31 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map_copy(char **map_copy, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

char	**copy_map(t_cub3d *game)
{
	char	**map_copy;
	int		i;
	int		rows;

	rows = 0;
	while (game->parse->map[rows])
		rows++;
	game->parse->rows = rows;
	map_copy = malloc(rows * sizeof(char *));
	if (!map_copy)
		exit(0);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(game->parse->map[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			printf("error\n");
			exit(0);
		}
		i++;
	}
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
			if (game->parse->map[y][x] == 'N' || game->parse->map[y][x] == 'S' || game->parse->map[y][x] == 'E'
				|| game->parse->map[y][x] == 'W')
			{
				game->parse->pxp = x;
				game->parse->pyp = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
	{
		printf("Map is not closed");
		exit(1);
	}
	if (map[y][x] == ' ' || map[y][x] == '\0')
	{
		printf("Map is not closed");
		exit(1);
	}
	if (map[y][x] != '0' && map[y][x] != '1')
		return ;
	if (map[y][x] == '1')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
