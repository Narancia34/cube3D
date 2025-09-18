/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_missing_cells.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:27:01 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/18 18:07:02 by fbicane          ###   ########.fr       */
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

void	replace_spaces(char **map)
{
	int	i;
	int	line;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (' ' == map[line][i])
				map[line][i] = '1';
		}
	}
}

void	complete_missing_cells(char **map)
{
	int		line_length;
	int		line;
	char	*line_to_free;

	line_length = max_line_length(map);
	line = -1;
	while (map[++line])
	{
		if (!(line_length > (int)ft_strlen(map[line])))
			continue ;
		line_to_free = map[line];
		map[line] = fixe_line(map[line], line_length);
		free(line_to_free);
	}
}
