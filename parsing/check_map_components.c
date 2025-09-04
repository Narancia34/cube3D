/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:07:39 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/04 23:20:54 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	max_line_length(char **map)
{
	int	result;
	int	i;
	int	temp;

	i = 0;
	result = ft_strlen(map[0]);
	while (map[++i])
	{
		temp = ft_strlen(map[i]);
		if (temp > result)
			result = temp;
	}
	return (result);
}

static char	*fixe_line(char *curent_map_line, int line_length)
{
	char	*result;
	int		i;

	result = malloc(line_length + 1);
	if (!result)
		exit(1);
	ft_strlcpy(result, curent_map_line, line_length + 1);
	i = ft_strlen(result);
	while (i < line_length)
	{
		result[i] = '?';
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	replace_space(char **map, int line)
{
	int	i;

	i = -1;
	while (map[line][++i])
	{
		if (' ' == map[line][i])
			map[line][i] = '1';
	}
}

void	fix_missing_cells(char **map)
{
	int		line_length;
	int		line;
	char	*line_to_free;

	line_length = max_line_length(map);
	line = -1;
	while (map[++line])
	{
		replace_space(map, line);
		if (!(line_length > (int)ft_strlen(map[line])))
			continue ;
		line_to_free = map[line];
		map[line] = fixe_line(map[line], line_length);
		free(line_to_free);
	}
}

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
			else if (c != '1' && c != '0' && c != 32)
				return (free_arr(map), parse_error(7, game));
		}
	}
	if (game->parse->player > 1)
		return (free_arr(map), parse_error(8, game));
	else if (game->parse->player == 0)
		return (free_arr(map), parse_error(9, game));
}

