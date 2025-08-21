/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:33 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/21 15:21:13 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	set_game_parse(t_cub3d *game)
{
	game->parse->file_name = NULL;
	game->parse->map = NULL;
	game->parse->north_texture = NULL;
	game->parse->south_texture = NULL;
	game->parse->east_texture = NULL;
	game->parse->west_texture = NULL;
}

int main(int ac, char **av)
{
	(void)ac;
	t_cub3d	game;
	
	ft_memset(&game, 0, sizeof(t_cub3d));
	game.parse = malloc(sizeof(t_parse));
	game.mechanics = malloc(sizeof(t_mechanics));
	game.parse->player = 0;
	set_game_parse(&game);
	game.mlx = mlx_init(500, 500, "parsing", true);
	parse_file(av, &game);
	if (load_textures(&game) != 0)
		destroy_parsing(&game);
	render_2d_map(&game);
	mlx_loop(game.mlx);
	destroy_parsing(&game);
	return (0);
}
