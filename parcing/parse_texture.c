/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:56:03 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 22:06:58 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**fetch_elemet(int cub_file, char **element)
{
	char	*file_line;

	free_arr(element);
	file_line = get_next_line(cub_file);
	while (ft_strncmp(file_line, " ", 0))
	{
		free(file_line);
		file_line = get_next_line(cub_file);
	}
	return (ft_split(file_line, ' '));
}

static mlx_image_t	*init_texture(char **element, t_cub3d *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (NULL != element[2])
	{
		free_arr(element);
		// WARN: check the get_next_line(-1);
		get_next_line(-1);
		parce_error(1, game);
	}
	texture = mlx_load_png(element[1]);
	if (NULL == texture)
	{
		free_arr(element);
		get_next_line(-1);
		parce_error(2, game);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

static void	parce_texture(char **element, t_cub3d *game)
{
	mlx_texture_t	*texture;

	if (ft_strncmp(element[0], "NO", 0))
		game->parce->north_texture = init_texture(element, game);
	else if (ft_strncmp(element[0], "SO", 0))
		game->parce->south_texture = mlx_texture_to_image(game->mlx, texture);
	else if (ft_strncmp(element[0], "WE", 0))
		game->parce->west_texture = mlx_texture_to_image(game->mlx, texture);
	else if (ft_strncmp(element[0], "EA", 0))
		game->parce->east_texture = mlx_texture_to_image(game->mlx, texture);
}

bool	parse_elements(int cub_file, t_cub3d *game)
{
	char	**element;
	int		count;

	element = NULL;
	count = 0;
	while (count < 5)
	{
		element = fetch_elemet(cub_file, element);
		parce_texture(element, game);

		count++;
	}

	return (true);
}
