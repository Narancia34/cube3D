/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 00:00:00 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/02 00:00:00 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_wall(t_cub3d *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->parse->rows)
		return (1);
	if (!game->parse->map[y] || x >= (int)strlen(game->parse->map[y]))
		return (1);
	return (game->parse->map[y][x] == '1');
}

double	cast_single_ray(t_cub3d *game, double ray_angle, int *hit_vertical, int *hit_x, int *hit_y)
{
	double	rayDirX = cos(ray_angle);
	double	rayDirY = sin(ray_angle);
	
	// Current grid position
	int	mapX = (int)game->pxp;
	int	mapY = (int)game->pyp;
	
	// Length of ray from current position to next side
	double	deltaDistX = fabs(1.0 / rayDirX);
	double	deltaDistY = fabs(1.0 / rayDirY);
	
	// Calculate step and initial sideDist
	int		stepX, stepY;
	double	sideDistX, sideDistY;
	
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (game->pxp - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - game->pxp) * deltaDistX;
	}
	
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (game->pyp - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - game->pyp) * deltaDistY;
	}
	
	// Perform DDA
	int	hit = 0;
	int	side;
	while (hit == 0)
	{
		// Jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		
		// Check if ray has hit a wall
		if (is_wall(game, mapX, mapY))
			hit = 1;
	}
	
	// Calculate distance
	double	perpWallDist;
	if (side == 0)
		perpWallDist = (mapX - game->pxp + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (mapY - game->pyp + (1 - stepY) / 2) / rayDirY;
	
	*hit_x = mapX;
	*hit_y = mapY;
	*hit_vertical = (side == 0) ? 1 : 0;
	
	return (perpWallDist);
}

mlx_image_t	*get_wall_texture(t_cub3d *game, int hit_x, int hit_y, int hit_vertical)
{
	double	player_x = game->pxp;
	double	player_y = game->pyp;
	
	if (hit_vertical)
	{
		// Vertical wall: check if we're hitting from left or right
		if (hit_x > player_x)
			return (game->parse->east_texture);   // Hit from left, show east face
		else
			return (game->parse->west_texture);   // Hit from right, show west face
	}
	else
	{
		// Horizontal wall: check if we're hitting from top or bottom
		if (hit_y > player_y)
			return (game->parse->south_texture);  // Hit from top, show south face
		else
			return (game->parse->north_texture);  // Hit from bottom, show north face
	}
}

int	get_texture_x(t_cub3d *game, double hit_x, double hit_y, int hit_vertical)
{
	double	wall_hit_point;
	int		texture_x;
	mlx_image_t	*texture = get_wall_texture(game, hit_x, hit_y, hit_vertical);
	
	if (hit_vertical)
		wall_hit_point = hit_y - floor(hit_y);
	else
		wall_hit_point = hit_x - floor(hit_x);
		
	texture_x = (int)(wall_hit_point * texture->width);
	
	if (texture_x >= (int)texture->width)
		texture_x = texture->width - 1;
	if (texture_x < 0)
		texture_x = 0;
		
	return (texture_x);
}

void	render_3d_scene(t_cub3d *game)
{
	int		x;
	double	ray_angle;
	double	distance;
	int		hit_vertical;
	int		hit_x, hit_y;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		y;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	
	// Convert RGB arrays to uint32_t colors
	ceiling_color = (game->parse->ceiling_color[0] << 24) | 
					(game->parse->ceiling_color[1] << 16) | 
					(game->parse->ceiling_color[2] << 8) | 0xFF;
	floor_color = (game->parse->floor_color[0] << 24) | 
				  (game->parse->floor_color[1] << 16) | 
				  (game->parse->floor_color[2] << 8) | 0xFF;
	
	x = 0;
	while (x < WIDTH)
	{
		// Calculate ray angle for current screen column
		ray_angle = game->player_angle - (FOV / 2) + ((double)x / WIDTH) * FOV;
		
		// Cast ray and get distance
		distance = cast_single_ray(game, ray_angle, &hit_vertical, &hit_x, &hit_y);
		
		// Fix fisheye effect
		distance *= cos(ray_angle - game->player_angle);
		
		// Calculate wall height on screen
		wall_height = (int)(HEIGHT / distance);
		wall_start = (HEIGHT - wall_height) / 2;
		wall_end = wall_start + wall_height;
		
		// Draw the column
		y = 0;
		while (y < HEIGHT)
		{
			if (y < wall_start)
				mlx_put_pixel(game->scene_image, x, y, ceiling_color);
			else if (y >= wall_start && y < wall_end)
			{
				uint32_t wall_color;
                wall_color = 0x00FF00FF;
				mlx_put_pixel(game->scene_image, x, y, wall_color);
			}
			else
				mlx_put_pixel(game->scene_image, x, y, floor_color);
			y++;
		}
		x++;
	}
}

void	cast_rays(t_cub3d *game)
{
	render_3d_scene(game);
}
