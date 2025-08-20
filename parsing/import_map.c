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

static int	check_file(char **av)
{
	int	len;

	if (!av[1])
		return (0);
	len = ft_strlen(av[1]);
	if (len < 4)
		return (0);
	if (ft_strncmp(av[1] + (len - 4), ".cub", 4) != 0)
		return (0);
	return (1);
}

static char	*read_map(int fd)
{
	char	*file;
	char	*temp;
	char	*line;

	file = ft_strdup("");
	if (fd < 0)
	{
		free(file);
		printf(RED"Error:\nInvalid file name!"RESET);
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = file;
		file = ft_strjoin(file, line);
		free(temp);
		free(line);
	}
	return (file);
}

char	**get_map(t_cub3d *game, char **av)
{
	int		fd;
	char	*file;
	char	**map;

	fd = open(av[1], O_RDWR);
	if (fd < 0)
	{
		printf(RED"ERROR:\nCannot open file!"RESET);
		exit(1);
	}
	file = read_map(fd);
	if (!file)
		exit (1);
	map = ft_split(file, '\n');
	free(file);
	close(fd);
	return (map);
}
