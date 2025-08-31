/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:11:25 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/30 14:10:02 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_handler(mlx_key_data_t key, void *param)
{
	t_cub3d	*game = (t_cub3d *)param;


	// player direction
	if (MLX_KEY_LEFT == key.key)
	{
		if (MLX_PRESS == key.action)
			game->mechanics->look_left = true;
		else if(MLX_RELEASE == key.action)
			game->mechanics->look_left = false;
	}
	else if (MLX_KEY_RIGHT == key.key)
	{
		if (MLX_PRESS == key.action)
			game->mechanics->look_right = true;
		else if(MLX_RELEASE == key.action)
			game->mechanics->look_right = false;
	}

	// player mouvment
	// TODO: player dosent register two keys at a time
	// maybe change else ifs to just ifs
	else if (MLX_KEY_W == key.key)
	{
		if (MLX_PRESS == key.action)
			game->mechanics->move_forward = true;
		else if(MLX_RELEASE == key.action)
			game->mechanics->move_forward = false;
	}
	else if (MLX_KEY_S == key.key)
	{
		if (MLX_PRESS == key.action)
			game->mechanics->move_backward = true;
		else if(MLX_RELEASE == key.action)
			game->mechanics->move_backward = false;
	}
	else if (MLX_KEY_D == key.key)
	{
		if (MLX_PRESS == key.action)
			game->mechanics->move_right = true;
		else if(MLX_RELEASE == key.action)
			game->mechanics->move_right = false;
	}
	else if (MLX_KEY_A == key.key)
	{
		if (MLX_PRESS == key.action)
			game->mechanics->move_left = true;
		else if(MLX_RELEASE == key.action)
			game->mechanics->move_left = false;
	}


	// escape key
	else if (MLX_KEY_ESCAPE == key.key && MLX_PRESS == key.action)
	{
		// TODO: close and terminate
		mlx_terminate(game->mlx);
		exit(0);
	}
}
