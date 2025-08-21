/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:56:03 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/13 12:07:23 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**fetch_elemet(t_cub3d *game)
{
	char	*file_line;
	char	**element;

	file_line = NULL;
	element = NULL;
	file_line = get_next_line(game->parse->cub_file);
	// WARN: file_line dosent contain "\n"
	// wrong check!
	while (!ft_strncmp(file_line, "\n", 0))
	{
		free(file_line);
		file_line = get_next_line(game->parse->cub_file);
	}
	element = ft_split(file_line, ' ');
	free(file_line);
	return (element);
}

static mlx_image_t	*init_texture(char **element, t_cub3d *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (NULL != element[2])
	{
		free_arr(element);
		// // WARN: check the get_next_line(-1);
		get_next_line(-1);
		parse_error(1, game);
	}
	// element[1][ft_strlen(element[1]) - 1] = '\0';
	texture = mlx_load_png(element[1]);
	if (NULL == texture)
	{
		free_arr(element);
		get_next_line(-1);
		parse_error(2, game);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

static void	parse_texture(char **element, t_cub3d *game)
{
	if (!ft_strncmp(element[0], "NO", 0))
		game->parse->north_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "SO", 0))
		game->parse->south_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "WE", 0))
		game->parse->west_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "EA", 0))
		game->parse->east_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "F", 0)
		|| !ft_strncmp(element[0], "C", 0))
		parse_rgb(element, game);
	else
		parse_error(4, game);
}

void	parse_elements(t_cub3d *game)
{
	char	**element;
	int		element_parsed;

	element = NULL;
	element_parsed = 0;
	while (element_parsed < 6)
	{
		free_arr(element);
		element = fetch_elemet(game);
		parse_texture(element, game);
		element_parsed++;
	}
	free_arr(element);
	// get_next_line(-1);
}
