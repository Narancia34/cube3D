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

void	check_map_components(t_cub3d *game, char **map)
{
	int	i;
	int	j;
	char	c;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			c = map[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			{
				game->parse->player_direction = c;
				game->parse->player++;
			}
			else if (c != '1' && c != '0')
				return (free_arr(map), parse_error(7, game));
		}
	}
	if (game->parse->player > 1)
		return (free_arr(map), parse_error(8, game));
	else if (game->parse->player == 0)
		return (free_arr(map), parse_error(9, game));
}

