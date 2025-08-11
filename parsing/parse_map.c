/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:40:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/11 14:25:41 by mgamraou         ###   ########.fr       */
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

int	parse_map(t_cub3d *game, char **av)
{
	game->parse->map = get_map(game, av);
	if (check_map_components(game) == 0)
		return (0);
	int i = -1;
	while (game->parse->map[++i])
		printf("%s\n", game->parse->map[i]);
	return 1;
}
