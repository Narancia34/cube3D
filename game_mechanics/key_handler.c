/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:11:25 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/01 10:37:10 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_rotation_key(t_cub3d *game, mlx_key_data_t *key)
{

	if (MLX_KEY_LEFT == key->key)
	{
		if (MLX_PRESS == key->action)
			game->mechanics->look_left = true;
		else if(MLX_RELEASE == key->action)
			game->mechanics->look_left = false;
	}
	else if (MLX_KEY_RIGHT == key->key)
	{
		if (MLX_PRESS == key->action)
			game->mechanics->look_right = true;
		else if(MLX_RELEASE == key->action)
			game->mechanics->look_right = false;
	}
}

static void	player_mouvement_key_helper(t_cub3d *game, mlx_key_data_t *key)
{
	if (MLX_KEY_D == key->key)
	{
		if (MLX_PRESS == key->action)
			game->mechanics->move_right = true;
		else if(MLX_RELEASE == key->action)
			game->mechanics->move_right = false;
	}
	else if (MLX_KEY_A == key->key)
	{
		if (MLX_PRESS == key->action)
			game->mechanics->move_left = true;
		else if(MLX_RELEASE == key->action)
			game->mechanics->move_left = false;
	}
}

static void	player_mouvement_key(t_cub3d *game, mlx_key_data_t *key)
{
	if (MLX_KEY_W == key->key)
	{
		if (MLX_PRESS == key->action)
			game->mechanics->move_forward = true;
		else if(MLX_RELEASE == key->action)
			game->mechanics->move_forward = false;
	}
	else if (MLX_KEY_S == key->key)
	{
		if (MLX_PRESS == key->action)
			game->mechanics->move_backward = true;
		else if(MLX_RELEASE == key->action)
			game->mechanics->move_backward = false;
	}
	player_mouvement_key_helper(game, key);
}

void	key_handler(mlx_key_data_t key, void *param)
{
	t_cub3d	*game = (t_cub3d *)param;

	player_rotation_key(game, &key);
	player_mouvement_key(game, &key);
	if (MLX_KEY_ESCAPE == key.key && MLX_PRESS == key.action)
	{
		// TODO: close and terminate
		mlx_terminate(game->mlx);
		exit(0);
	}
}
