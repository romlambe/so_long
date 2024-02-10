/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:42:35 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/09 16:38:25 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook_switch(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (keycode == KEY_Z)

	if (keycode == KEY_Q)

	if (keycode == KEY_S)

	if (keycode == KEY_D)
		;
}

void	move_up(t_data *game)
{
	
}
