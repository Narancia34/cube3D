/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:35:24 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/11 14:17:41 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libs/MLX42/include/MLX42/MLX42.h"
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


// INFO: Game main struct
/*-----------------------------------------------*/
typedef struct s_cub3d {
	t_parse	*parse;
}	t_cub3d;
/*-----------------------------------------------*/

// INFO: parcing struct
/*-----------------------------------------------*/
struct s_parse {
	char		*file_name;
	char		**map;
	mlx_image_t	*north_texture;
	mlx_image_t	*south_texture;
	mlx_image_t	*east_texture;
	mlx_image_t	*west_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	int			player;
	char			player_direction;
};
/*-----------------------------------------------*/


int	parse_map(t_cub3d *game, char **av);
char	**get_map(t_cub3d *game, char **av);


#endif
