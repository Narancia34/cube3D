/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:40:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/05 00:33:59 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*read_map(int fd)
{
	char	*file;
	char	*temp;
	char	*line;

	file = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
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

	file = read_map(game->parse->cub_file);
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
	find_player_position(game);
}
