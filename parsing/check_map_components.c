/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:07:39 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/05 16:09:52 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_player_angle(t_cub3d *game, char direction, int *player)
{
	if ('N' == direction)
		game->player_angle = -M_PI / 2.0;
	else if ('S' == direction)
		game->player_angle = M_PI / 2.0;
	else if ('W' == direction)
		game->player_angle = M_PI;
	else if ('E' == direction)
		game->player_angle = 0.0;
	(*player)++;
}

void	check_map_components(t_cub3d *game, char **map)
{
	int		i;
	int		j;
	int		player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S')
				set_player_angle(game, map[i][j], &player);
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'D')
				return (free_arr(map), parse_error(7, game));
		}
	}
	if (player > 1)
		return (free_arr(map), parse_error(8, game));
	else if (0 == player)
		return (free_arr(map), parse_error(9, game));
}
