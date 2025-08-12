/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:47:55 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/12 19:04:36 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**extract_rgb(char **element, t_cub3d *game)
{
	char	**colors;

	if (NULL != element[2])
	{
		get_next_line(-1);
		free_arr(element);
		parse_error(1, game);
	}
	colors = ft_split(element[1], ',');
	check_rgb_values(colors, element, game);
	if (NULL != colors[3])
	{
		free_arr(element);
		free_arr(colors);
		get_next_line(-1);
		parse_error(1, game);
	}
	return (colors);
}

static bool	is_rgb_in_range(int *rgb)
{
	return ((rgb[0] >= 0 && rgb[0] <= 255)
		&& (rgb[1] >= 0 && rgb[1] <= 255)
		&& (rgb[2] >= 0 && rgb[2] <= 255));
}

static bool	asign_rgb(char **colors, char **element, t_cub3d *game)
{
	int	rgb[3];

	rgb[0] = ft_atoi(colors[0]);
	rgb[1] = ft_atoi(colors[1]);
	rgb[2] = ft_atoi(colors[2]);
	if (!is_rgb_in_range(rgb))
		return (free_arr(element), free_arr(colors),
			parse_error(3, game), false);
	else if (ft_strncmp(element[0], "F", 0)
		&& ft_strncmp(element[0], "C", 0))
		return (false);
	if (!ft_strncmp(element[0], "F", 0))
	{
		game->parse.floor_color[0] = rgb[0];
		game->parse.floor_color[1] = rgb[1];
		game->parse.floor_color[2] = rgb[2];
	}
	else if (!ft_strncmp(element[0], "C", 0))
	{
		game->parse.ceiling_color[0] = rgb[0];
		game->parse.ceiling_color[1] = rgb[1];
		game->parse.ceiling_color[2] = rgb[2];
	}
	return (true);
}

static void	init_rgb(char **colors, char **element, t_cub3d *game)
{
	if (!asign_rgb(colors, element, game))
	{
		free_arr(element);
		free_arr(colors);
		parse_error(4, game);
	}
	free_arr(colors);
}

void	parse_rgb(char **element, t_cub3d *game)
{
	char	**colors;

	colors = extract_rgb(element, game);
	init_rgb(colors, element, game);
}
