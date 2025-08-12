/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:33 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/09 21:38:02 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	set_game_parse(t_cub3d *game)
{
	game->parce->map = NULL;
	game->parce->east_texture = NULL;
	game->parce->north_texture = NULL;
	game->parce->south_texture = NULL;
	game->parce->west_texture = NULL;
	game->parce->file_name = NULL;
}

int main(int ac, char **av)
{
	t_cub3d	game;

	set_game_parse(&game);
	(void)ac;
	game.mlx = mlx_init(500, 500, "parsing", false);
	parse_file(av, &game);
	return (0);
}
