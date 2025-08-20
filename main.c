/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:33 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 12:13:33 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	set_game_parse(t_cub3d *game)
{
	game->parse.file_name = NULL;
	game->parse.map = NULL;
	game->parse.north_texture = NULL;
	game->parse.south_texture = NULL;
	game->parse.east_texture = NULL;
	game->parse.west_texture = NULL;
}

int main(int ac, char **av)
{
	(void)ac;
	t_cub3d	game;
	ft_memset(&game, 0, sizeof(t_cub3d));
	game.parse = malloc(sizeof(t_parse));
	game.parse->player = 0;
	set_game_parse(&game);
	game.mlx = mlx_init(500, 500, "parsing", true);
	parse_file(av, &game);
	parse_map(&game, av);
	destroy_parsing(&game);
	return (0);
}
