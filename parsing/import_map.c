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

static char	*read_map(int fd)
{
	char	*file;
	char	*temp;
	char	*line;

	file = ft_strdup("");
	// if (fd < 0)
	// {
	// 	free(file);
	// 	printf(RED"Error:\nInvalid file name!"RESET);
	// 	return (NULL);
	// }

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

char	**get_map(t_cub3d *game)
{
	char	*file;
	char	**map;

	file = read_map(game->parse->cub_file);
	if (!file)
		exit (1);
	// printf("%s", file);
	// printf("================================================\n");
	map = ft_split(file, '\n');
	// for (int i = 0; map[i]; i++)
	// 	printf("%s\n", map[i]);
	// printf("-----");
	free(file);
	return (map);
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

