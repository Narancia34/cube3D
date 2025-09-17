/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:35:24 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/17 21:32:13 by fbicane          ###   ########.fr       */
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


# ifndef HEIGHT
#  define HEIGHT 660
# endif
# ifndef WIDTH
#  define WIDTH 1280
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
	int		is_door;
	double	wallx;
		double	step;
	double	text_pos;
	int	tex_x;
	int	tex_y;
	mlx_image_t *texture;
} t_ray;

typedef struct s_textures{
	mlx_image_t	*north_texture;
	mlx_image_t	*south_texture;
	mlx_image_t	*east_texture;
	mlx_image_t	*west_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	mlx_image_t *gun_frames[15];
	mlx_image_t	*mini_map;
} t_textures;

// INFO: parcing struct
/*-----------------------------------------------*/
typedef struct s_parse {
	int			cub_file;
	char		*file_name; // WARN: not used
	// int			pxp;
	// int			pyp;
	int			rows;
}	t_parse;

/*-----------------------------------------------*/


typedef struct s_mechanics {
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
	bool		pause_game;
}	t_mechanics;


// INFO: Game main struct
/*-----------------------------------------------*/
typedef struct s_cub3d {
	mlx_t		*mlx;
	t_parse		parse;
	t_mechanics	mechanics;
	double		pxp;
	double		pyp;
	double		player_angle;
	t_ray		ray;
	t_textures textures;

	char		**map;
	// gun frames
	bool		attack_animation;
	int			gun_frame;
	double		anim_timer;
}	t_cub3d;
/*-----------------------------------------------*/


void	parse_map(t_cub3d *game);
char	**copy_map(t_cub3d *game);
void	free_map_copy(char **map_copy, int rows);
void	find_player_position(t_cub3d *game);
void	destroy_game(t_cub3d *game, int exit_status);
void	parse_error(int error_code, t_cub3d *game);
void	check_rgb_values(char **colors, char **element, t_cub3d *game);
void	parse_rgb(char **element, t_cub3d *game);
void	parse_elements(t_cub3d *game);
void	parse_file(char **av, t_cub3d *game);
void	check_map_components(t_cub3d *game, char **map);
void	complete_missing_cells(char **map);
void	check_closed_map(char **map, t_cub3d *game);
void	replace_spaces(char **map);

void	render_2d_map(void *param);
int		load_textures(t_cub3d *game);
void	key_handler(mlx_key_data_t key, void *param);
void	update_game(void *param);
void	player_mouvement(t_cub3d *game);
void	player_rotation(t_cub3d *game);
void    cast_rays(t_cub3d *game);
void	cursor_handler(double xpos, double ypos, void *param);
void	interact_with_doors(t_cub3d *game);
void	play_gun_animation(t_cub3d *game);
void	update_gun_animation(t_cub3d *game);
void	load_gun_frames(t_cub3d *game);
void	init_gun_frames(t_cub3d *game);
void	render_mini_map(t_cub3d *game);
void	texture_mapping(t_cub3d *game, int x);
void	draw_wall_line(t_cub3d *game, int x);
void mouse_click_handler(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

#endif
