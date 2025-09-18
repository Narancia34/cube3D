/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:56:03 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/18 18:07:02 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**fetch_elemet(t_cub3d *game)
{
	char	*file_line;
	char	**element;

	file_line = NULL;
	element = NULL;
	file_line = get_next_line(game->parse.cub_file);
	while (!(*file_line))
	{
		free(file_line);
		file_line = get_next_line(game->parse.cub_file);
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
		get_next_line(-1);
		parse_error(1, game);
	}
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
		game->textures.north_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "SO", 0))
		game->textures.south_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "WE", 0))
		game->textures.west_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "EA", 0))
		game->textures.east_texture = init_texture(element, game);
	else if (!ft_strncmp(element[0], "F", 0)
		|| !ft_strncmp(element[0], "C", 0))
		parse_rgb(element, game);
	else
		parse_error(4, game);
}

static void	check_parsed_elements(t_cub3d *game)
{
	if (!game->textures.north_texture
		|| !game->textures.south_texture
		|| !game->textures.east_texture
		|| !game->textures.west_texture
		|| !game->parse.ceiling_color
		|| !game->parse.floor_color)
		parse_error(13, game);
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
	check_parsed_elements(game);
}
