/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:16:22 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/18 20:17:43 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_wall_height(t_cub3d *game)
{
	game->ray.wall_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	game->ray.wall_start = (HEIGHT - game->ray.wall_height) / 2;
	game->ray.wall_end = game->ray.wall_start + game->ray.wall_height;
}

void	cast_rays(t_cub3d *game)
{
	int		x;
	double	ray_angle;

	x = 0;
	game->ray.wall_height = 0;
	game->ray.wall_start = 0;
	game->ray.wall_end = 0;
	while (x < WIDTH)
	{
		ray_angle = game->player_angle - (FOV / 2) + ((double)x / WIDTH) * FOV;
		cast_single_ray(game, ray_angle);
		texture_mapping(game, x);
		game->ray.perp_wall_dist *= cos(ray_angle - game->player_angle);
		calculate_wall_height(game);
		draw_wall_line(game, x);
		x++;
	}
}
