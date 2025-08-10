/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:56:03 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 12:39:16 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fetch_elemet(int cub_file, char **element)
{
	char	*file_line;

	free_arr(element);
	file_line = get_next_line(cub_file);
	while (ft_strncmp(file_line, " ", 0))
	{
		free(file_line);
		file_line = get_next_line(cub_file);
	}
	element = ft_split(file_line, ' ');
}

static void	parce_colors(char **element, t_cub3d *game, char identifier)
{
	char	**colors;

	colors = ft_split(element[1], ',');
	if (colors[3])
	{
		printf(RED"Parcing error\n"RESET);
		free_arr(colors);
		free_arr(element);
		// destroy_parcing();
	}
	if ('F' == identifier)
	{
		// WARN: protect element[0] if its greater than int max
		game->parce->floor_color[0] = ft_atoi(element[0]);
	}
}

static mlx_image_t	*init_texture(char **element, t_cub3d *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	// TODO: protect if elements has more than 2 char *
	texture = mlx_load_png(element[1]);
	if (NULL == texture)
	{
		printf(RED"Failed loading textures\n"RESET);
		free_arr(element);
		mlx_delete_texture(texture);
		exit(1);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	// TODO: Destroy the texture
	return (image);
}

static void	parce_texture(char **element, t_cub3d *game)
{
	mlx_texture_t	*texture;

	if (ft_strncmp(element[0], "NO", 0))
	{
		game->parce->north_texture = init_texture(element, game);
	}
	else if (ft_strncmp(element[0], "SO", 0))
	{
		texture = mlx_load_png(element[1]);
		if (NULL == texture)
			return ;
		game->parce->south_texture = mlx_texture_to_image(game->mlx, texture);
	}
	else if (ft_strncmp(element[0], "WE", 0))
	{
		texture = mlx_load_png(element[1]);
		if (NULL == texture)
			return ;
		game->parce->west_texture = mlx_texture_to_image(game->mlx, texture);
	}
	else if (ft_strncmp(element[0], "EA", 0))
	{
		texture = mlx_load_png(element[1]);
		if (NULL == texture)
			return ;
		game->parce->east_texture = mlx_texture_to_image(game->mlx, texture);
	}
	else if (ft_strncmp(element[0], "F", 0))
	{
		
	}
}

bool	parce_elements(int cub_file, t_cub3d *game)
{
	char	**element;
	int		count;

	element = NULL;
	count = 0;
	while (count < 5)
	{

		fetch_elemet(cub_file, element);

		count++;
	}

	return (true);
}
