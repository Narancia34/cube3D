/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:40:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/05 15:53:14 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*skip_newlines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (!line[0])
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static char	*check_rest_of_file(t_cub3d *game, char *file)
{
	char	*line;

	line = get_next_line(game->parse->cub_file);
	while (line)
	{
		if (line[0])
		{
			free(line);
			free(file);
			parse_error(11, game);
		}
		free(line);
		line = get_next_line(game->parse->cub_file);
	}
	return (file);
}

static char	*read_map(t_cub3d *game)
{
	char	*file;
	char	*temp;
	char	*line;

	file = skip_newlines(game->parse->cub_file);
	temp = file;
	file = ft_strjoin(file, "\n");
	free(temp);
	while (1)
	{
		line = get_next_line(game->parse->cub_file);
		if (!line)
			break ;
		if (!line[0])
			return (free(line), check_rest_of_file(game ,file));
		temp = file;
		file = ft_strjoin(file, line);
		free(temp);
		temp = file;
		file = ft_strjoin(file, "\n");
		free(temp);
		free(line);
	}
	return (file);
}

void	get_map(t_cub3d *game)
{
	char	*file;
	char	**map;

	file = read_map(game);
	if (!file)
		exit (1);
	map = ft_split(file, '\n');
	game->parse->map = map;
	free(file);
}

void	parse_map(t_cub3d *game)
{
	char	**map;

	get_map(game);
	map = copy_map(game);
	check_map_components(game, map);
	complete_missing_cells(map);
	check_closed_map(map, game);
	find_player_position(game);
	free_arr(map);
}
