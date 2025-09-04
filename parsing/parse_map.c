/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:40:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/09/05 00:16:47 by fbicane          ###   ########.fr       */
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

	get_map(game);
	find_player_position(game);
}
