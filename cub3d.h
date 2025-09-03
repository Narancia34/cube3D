/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:35:24 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/01 10:02:44 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libs/MLX42/include/MLX42/MLX42.h"
# include "./libs/My_library/my_library.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <fcntl.h>
# include "./libs/My_library/my_library.h"

// INFO: colors
/*-----------------------------------------------*/
# ifndef BLUE
#  define BLUE  "\001\033[34m\002"
# endif
# ifndef GREEN
#  define GREEN "\001\033[32m\002"
# endif
# ifndef RED
#  define RED   "\001\033[31m\002"
# endif
# ifndef YELLOW
#  define YELLOW "\001\033[0;33m\002"
# endif
# ifndef RESET
#  define RESET "\001\033[0m\002"
# endif
/*-----------------------------------------------*/

typedef struct s_parse t_parse;
typedef struct s_mechanics t_mechanics;

# ifndef HEIGHT
#  define HEIGHT 660
# endif
# ifndef WIDTH
#  define WIDTH 660
# endif

# ifndef FOV
#  define FOV 1.0472 // 60 degrees in radians
# endif

typedef enum {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
} t_move;

typedef struct s_ray{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		wall_height;
	int		wall_start;
	int		wall_end;
} t_ray;

// INFO: Game main struct
/*-----------------------------------------------*/
typedef struct s_cub3d {
	mlx_t		*mlx;
	t_parse		*parse;
	t_mechanics	*mechanics;
	double		pxp;
	double		pyp;
	double		player_angle;
	mlx_image_t	*scene_image;
	t_ray		ray;
}	t_cub3d;
/*-----------------------------------------------*/


// INFO: parcing struct
/*-----------------------------------------------*/
struct s_parse {
	int			cub_file;
	char		*file_name;
	char		**map;
	mlx_image_t	*north_texture;
	mlx_image_t	*south_texture;
	mlx_image_t	*east_texture;
	mlx_image_t	*west_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	int			player;
	char		player_direction;
	int			pxp;
	int			pyp;
	int			rows;
};
/*-----------------------------------------------*/

struct s_mechanics {
	mlx_image_t	*img1;
	mlx_image_t	*img2;
	mlx_image_t	*player;

	// player rotation
	int			pxd;
	int			pyd;
	bool		look_left;
	bool		look_right;

	// player mouvment
	bool		move_forward;
	bool		move_backward;
	bool		move_right;
	bool		move_left;
};


void	parse_map(t_cub3d *game);
char	**get_map(t_cub3d *game);
char	**copy_map(t_cub3d *game);
void	free_map_copy(char **map_copy, int rows);
void	find_player_position(t_cub3d *game);
void	flood_fill(char **map, int x, int y);
void	destroy_parsing(t_cub3d *game);
void	parse_error(int error_code, t_cub3d *game);
void	check_rgb_values(char **colors, char **element, t_cub3d *game);
void	parse_rgb(char **element, t_cub3d *game);
void	parse_elements(t_cub3d *game);
void	parse_file(char **av, t_cub3d *game);
void	render_2d_map(void *param);
int		load_textures(t_cub3d *game);
void	key_handler(mlx_key_data_t key, void *param);
void	update_game(void *param);
void	player_mouvement(t_cub3d *game);
void	player_rotation(t_cub3d *game);
void    cast_rays(t_cub3d *game);

#endif
