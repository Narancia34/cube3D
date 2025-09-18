/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:16:43 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/18 16:27:02 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_non_doors_utils(t_cub3d *game)
{
	if (game->ray.side == 0 && game->ray.step_x == -1)
	{
		if (game->map[game->ray.map_y][game->ray.map_x + 1] == 'O')
		{
			game->ray.texture = game->textures.door;
		}
		else
			game->ray.texture = game->textures.west_texture;
	}
	else if (game->ray.side == 0 && game->ray.step_x == 1)
	{
		if (game->map[game->ray.map_y][game->ray.map_x - 1] == 'O')
		{
			game->ray.texture = game->textures.door_side;
		}
		else
			game->ray.texture = game->textures.east_texture;
	}
}

void	render_non_doors(t_cub3d *game)
{
	if (game->ray.side == 1 && game->ray.step_y == -1)
	{
		if (game->map[game->ray.map_y + 1][game->ray.map_x] == 'O')
			game->ray.texture = game->textures.door_side;
		else
			game->ray.texture = game->textures.north_texture;
	}
	else if (game->ray.side == 1 && game->ray.step_y == 1)
	{
		if (game->map[game->ray.map_y - 1][game->ray.map_x] == 'O')
			game->ray.texture = game->textures.door;
		else
			game->ray.texture = game->textures.south_texture;
	}
	else
		render_non_doors_utils(game);
}
