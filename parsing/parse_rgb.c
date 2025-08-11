/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:47:55 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/11 12:55:30 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**extract_rgb(char **element, t_cub3d *game)
{
	char **colors;

	if (NULL != element[2])
	{
		get_next_line(-1);
		free_arr(element);
		parse_error(1, game);
	}
	colors = ft_split(element[1], ',');
	if (NULL != colors[3])
	{
		free_arr(element);
		free_arr(colors);
		get_next_line(-1);
		parse_error(1, game);
	}
	return (colors);
}

static bool	is_rgb_in_range(t_cub3d *game, char element)
{
	int	r;
	int	g;
	int	b;

	if ('F' == element)
	{
		r = game->parce->floor_color[0];
		g = game->parce->floor_color[1];
		b = game->parce->floor_color[2];
		return ((r >= 0 && r <= 255) && (g >= 0 && g <= 255)
				&& (b >= 0 && b <= 255));
	}
	else if ('C' == element)
	{
		r = game->parce->ceiling_color[0];
		g = game->parce->ceiling_color[1];
		b = game->parce->ceiling_color[2];
		return ((r >= 0 && r <= 255) && (g >= 0 && g <= 255)
				&& (b >= 0 && b <= 255));
	}
	return (false);
}

static void	init_rgb(char **colors, char **element, t_cub3d *game)
{
	if (ft_strncmp(element[0], "F", 0))
	{
		game->parce->floor_color[0] = ft_atoi(colors[0]);
		game->parce->floor_color[1] = ft_atoi(colors[1]);
		game->parce->floor_color[2] = ft_atoi(colors[2]);
		if (!is_rgb_in_range(game, 'F'))
			return (free_arr(element),
					free_arr(colors), parse_error(3, game));
	}
	else if (ft_strncmp(element[0], "C", 0))
	{
		game->parce->ceiling_color[0] = ft_atoi(colors[0]);
		game->parce->ceiling_color[1] = ft_atoi(colors[1]);
		game->parce->ceiling_color[2] = ft_atoi(colors[2]);
		if (!is_rgb_in_range(game, 'C'))
			return (free_arr(element),
					free_arr(colors), parse_error(3, game));
	}
	else
	{
		free_arr(element);
		free_arr(colors);
		parse_error(4, game);
	}
}

void	parse_rgb(char **element, t_cub3d *game)
{
	char	**colors;

	colors = extract_rgb(element, game);
	init_rgb(colors, element, game);
}
