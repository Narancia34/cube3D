/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:30:32 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/10 15:31:50 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	player_direction(t_cub3d *game)
{
	double	player_angle;

	player_angle = fmod(game->player_angle, 2 * M_PI);
	if (player_angle < 0)
		player_angle += 2 * M_PI;
	if (player_angle > M_PI / 4.0 && player_angle < 3 * M_PI / 4.0)
		return ('S');
	else if (player_angle > 3 * M_PI / 4.0 && player_angle < 5 * M_PI / 4.0)
		return ('W');
	else if (player_angle > 5 * M_PI / 4.0 && player_angle < 7 * M_PI / 4.0)
		return ('N');
	return ('E');
}

bool	open_doors(int pxp, int pyp, char **map, char direction)
{
	if ('N' == direction && 'D' == map[pyp - 1][pxp])
	{
		map[pyp - 1][pxp] = 'O';
		return (true);
	}
	else if ('W' == direction && 'D' == map[pyp][pxp - 1])
	{
		map[pyp][pxp - 1] = 'O';
		return (true);
	}
	else if ('S' == direction && 'D' == map[pyp + 1][pxp])
	{
		map[pyp + 1][pxp] = 'O';
		return (true);
	}
	else if ('E' == direction && 'D' == map[pyp][pxp + 1])
	{
		map[pyp][pxp + 1] = 'O';
		return (true);
	}
	return (false);
}

void	close_doors(int pxp, int pyp, char **map, char direction)
{
	if ('N' == direction && 'O' == map[pyp - 1][pxp])
		map[pyp - 1][pxp] = 'D';
	else if ('W' == direction && 'O' == map[pyp][pxp - 1])
		map[pyp][pxp - 1] = 'D';
	else if ('S' == direction && 'O' == map[pyp + 1][pxp])
		map[pyp + 1][pxp] = 'D';
	else if ('E' == direction && 'O' == map[pyp][pxp + 1])
		map[pyp][pxp + 1] = 'D';
}

void	interact_with_doors(t_cub3d *game)
{
	int		pxp;
	int		pyp;
	char	**map;
	char	direction;

	pxp = (int)floor(game->pxp);
	pyp = (int)floor(game->pyp);
	map = game->map;
	direction = player_direction(game);
	if (!open_doors(pxp, pyp, map, direction))
		close_doors(pxp, pyp, map, direction);
}
