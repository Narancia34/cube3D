/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:31:39 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/05 16:07:00 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_first_line(char **map, t_cub3d *game)
{
	int	i;

	i = 0;
	while (('?' != map[0][i] || map[0][i]) && '1' == map[0][i])
		i++;
	if (map[0][i] && '?' != map[0][i])
	{
		free_arr(map);
		parse_error(10, game);
	}
}

static void	check_last_line(int j, char **map, t_cub3d *game)
{
	int	i;

	i = 1;
	if (!map[j + 1])
	{
		if ('1' != map[j][0])
		{
			free_arr(map);
			parse_error(10, game);
		}
		while (('?' != map[j][i] || map[j][i]) && '1' == map[j][i])
			i++;
		if (map[j][i] && '?' != map[j][i])
		{
			free_arr(map);
			parse_error(10, game);
		}
	}
}

static void	check_midle_lines(int j, char **map, t_cub3d *game)
{
	int	i;

	i = 1;
	if ('1' != map[j][0])
		return (free_arr(map), parse_error(10, game));
	while ('?' != map[j][i] && map[j][i])
		i++;
	if (!map[j][i] && '1' == map[j][i - 1])
		return ;
	else if (!map[j][i] && ('0' == map[j][i - 1]
				|| ft_strrchr("NEWS", map[j][i])))
		return (free_arr(map), parse_error(10, game));
	else if (map[j][i] && '?' == map[j][i])
	{
		if  ('1' != map[j][i - 1])
			return (free_arr(map), parse_error(10, game));
		while (map[j][i])
		{
			if (('?' == map[j - 1][i] || '1' == map[j - 1][i])
					&& (('?' == map[j + 1][i] || '1' == map[j + 1][i])))
				i++;
			else
				return (free_arr(map), parse_error(10, game));
		}
	}
}

void	check_closed_map(char **map, t_cub3d *game)
{
	int	line;

	check_first_line(map, game);
	line = 0;
	while (map[++line])
	{
		if (!map[line + 1])
			return (check_last_line(line, map, game));
		check_midle_lines(line, map, game);
	}
}
