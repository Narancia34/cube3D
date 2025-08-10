/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:40:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/08/10 11:48:50 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file(char **av)
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

char	*read_map(int fd)
{
	char	*file;
	char	*temp;
	char	*line;

	file = ft_strdup("");
	if (fd < 0)
	{
		free(file);
		ft_printf("ERROR:\nInvalid file name!!");
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
		printf("ERROR:\nCannot open file!");
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

int	parce_map(t_cub3d *game, char **av)
{
	game->parce->map = get_map(game, av);
	int	i = 0;
	while (game->parce->map[i])
	{
		printf("%s\n", game->parce->map[i]);
		i++;
	}
	return 0;
}
