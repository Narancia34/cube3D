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
	while (map[0][i] && '1' == map[0][i])
		i++;
	if (map[0][i] && '?' != map[0][i])
		return (free_arr(map), parse_error(10, game));
	while (map[0][i])
	{
		if (!map[1][i])
			return ;
		if ('?' != map[1][i] && '1' != map[1][i])
			return (free_arr(map), parse_error(10, game));
		i++;
	}
}

static void	check_last_line(int line, char **map, t_cub3d *game)
{
	int	i;

	i = 0;
	while (map[line][i] && '1' == map[line][i])
		i++;
	if (map[line][i] && '?' != map[line][i])
		return (free_arr(map), parse_error(10, game));
	while (map[line][i])
	{
		if (!map[line - 1][i])
			return ;
		if (('?' != map[line - 1][i] && '1' != map[line - 1][i]))
			return (free_arr(map), parse_error(10, game));
		i++;
	}
}

static void	check_midle_lines(int line, char **map, t_cub3d *game)
{
	int	i;

	i = 1;
	if ('1' != map[line][0])
		return (free_arr(map), parse_error(10, game));
	while ('?' != map[line][i] && map[line][i])
		i++;
	if (!map[line][i] && '1' == map[line][i - 1])
		return ;
	else if (!map[line][i] && ('0' == map[line][i - 1]
				|| ft_strrchr("NEWS", map[line][i])))
		return (free_arr(map), parse_error(10, game));
	else if (map[line][i] && '?' == map[line][i])
	{
		if ('1' != map[line][i - 1])
			return (free_arr(map), parse_error(10, game));
		while (map[line][i])
		{
			if (('?' == map[line - 1][i] || '1' == map[line - 1][i])
					&& (('?' == map[line + 1][i] || '1' == map[line + 1][i])))
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
