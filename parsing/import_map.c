/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:07:39 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/11 14:26:26 by mgamraou         ###   ########.fr       */
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
