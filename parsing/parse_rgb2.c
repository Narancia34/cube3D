/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:37:37 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/18 18:07:02 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static bool is_numbers(char **colors)
// {
// 	int	i;
// 	int	j;
//
// 	j = 0;
// 	while (colors[j])
// 	{
// 		i = 0;
// 		while(colors[j][i])
// 		{
// 			if (!ft_isdigit(**colors))
// 				return (false);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (true);
// }
//
// void	check_rgb_values(char **colors, char **element, t_cub3d *game)
// {
// 	if (!is_numbers(colors))
// 	{
// 		free_arr(colors);
// 		free_arr(element);
// 		parse_error(3, game);
// 	}
// }

void	check_rgb_values(char **element, t_cub3d *game)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (element[1][++i])
	{
		if (',' == element[1][i])
			count++;
		else if (!ft_isdigit(element[1][i]))
		{
			free_arr(element);
			parse_error(12, game);
		}
	}
	if (count > 3)
	{
		free_arr(element);
		parse_error(12, game);
	}
}
