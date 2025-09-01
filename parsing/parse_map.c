/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:40:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/01 09:50:50 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_components(t_cub3d *game)
{
	int	i;
	int	j;
	char	c;

	i = -1;
	while (game->parse->map[++i])
	{
		j = -1;
		while (game->parse->map[i][++j])
		{
			c = game->parse->map[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			{
				game->parse->player_direction = c;
				game->parse->player++;
			}
			else if (c != '1' && c != '0' && c != 32)
				return (printf(RED"Error:\nExtra map component"RESET), 0);
		}
	}
	if (game->parse->player > 1)
		return (printf(RED"Error:\nMore than one starting position"RESET), 0);
	else if (game->parse->player == 0)
		return (printf(RED"Error:\nNo starting position"RESET), 0);
	return (1);
}

void	parse_map(t_cub3d *game)
{
	char	**map_copy;

	game->parse->map = get_map(game);
	if (check_map_components(game) == 0)
		destroy_parsing(game);
	map_copy = copy_map(game);
	find_player_position(game);
	map_copy[game->parse->pyp][game->parse->pxp] = '0';
	flood_fill(map_copy, game->parse->pxp, game->parse->pyp);
	free_arr(map_copy);
	if ('N' == game->parse->player_direction)
		game->player_angle = -M_PI/2.0;
	else if ('S' == game->parse->player_direction)
		game->player_angle = M_PI / 2.0;
	else if ('W' == game->parse->player_direction)
		game->player_angle = M_PI;
	else if ('E' == game->parse->player_direction)
		game->player_angle = 0.0;
}
