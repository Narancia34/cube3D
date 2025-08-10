/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:35:24 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 11:46:21 by mgamraou         ###   ########.fr       */
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

typedef struct s_parce t_parce;


// INFO: Game main struct
/*-----------------------------------------------*/
typedef struct s_cub3d {
	t_parce	*parce;
}	t_cub3d;
/*-----------------------------------------------*/

// INFO: parcing struct
/*-----------------------------------------------*/
struct s_parce {
	char		*file_name;
	char		**map;
	mlx_image_t	*north_texture;
	mlx_image_t	*south_texture;
	mlx_image_t	*east_texture;
	mlx_image_t	*west_texture;
	int			floor_color[3];
	int			ceiling_color[3];
};
/*-----------------------------------------------*/


int	parce_map(t_cub3d *game, char **av);
char	**get_map(t_cub3d *game, char **av);
char	*read_map(int fd);
int	check_file(char **av);


#endif
