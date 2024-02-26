/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:42:35 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/13 12:17:05 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hook_switch(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		exit(0);
		//ft tout free;
	}
	// else if (keycode == KEY_Z)
	// 	move_up(game);
	// else if (keycode == KEY_Q)
	// 	move_left(game);
	// else if (keycode == KEY_S)
	// 	move_down(game);
	// else if (keycode == KEY_D)
	// 	move_right(game);
	return (0);
}

void	move_up(t_data *game)
{
	if (game->player.pos_y - 1 == '0')
	{
		game->player.pos_y--;
		game->step_count++;
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_y - 1 == 'C')
	{
		game->player.pos_y--;
		game->step_count++;
		game->collectible--;

		//passer le collecible en floor
		mlx_xpm_file_to_image(game->mlx, "../xpm/grass.xpm", 16, 16);
		game->map[game->player.pos_y][game->player.pos_x] = 'O';
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_y - 1 == 'E')
	{
		if (game->collectible == 0)
			mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF0000, "Félicitations vous avez gagné");
	}
}

void	move_down(t_data *game)
{
	if (game->player.pos_y + 1 == '0')
	{
		game->player.pos_y++;
		game->step_count++;
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_y + 1 == 'C')
	{
		game->player.pos_y++;
		game->step_count++;
		game->collectible--;

		//passer le collecible en floor
		mlx_xpm_file_to_image(game->mlx, "../xpm/grass.xpm", 16, 16);
		game->map[game->player.pos_y][game->player.pos_x] = 'O';
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_y + 1 == 'E')
	{
		if (game->collectible == 0)
			mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF0000, "Félicitations vous avez gagné");
	}
}

void	move_right(t_data *game)
{
	if (game->player.pos_x + 1 == '0')
	{
		game->player.pos_x++;
		game->step_count++;
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_x -+1 == 'C')
	{
		game->player.pos_x++;
		game->step_count++;
		game->collectible--;

		//passer le collecible en floor
		mlx_xpm_file_to_image(game->mlx, "../xpm/grass.xpm", 16, 16);
		game->map[game->player.pos_y][game->player.pos_x] = 'O';
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_x + 1 == 'E')
	{
		if (game->collectible == 0)
			mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF0000, "Félicitations vous avez gagné");
	}
}

void	move_left(t_data *game)
{
	if (game->player.pos_x - 1 == '0')
	{
		game->player.pos_x--;
		game->step_count++;
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_x - 1 == 'C')
	{
		game->player.pos_x--;
		game->step_count++;
		game->collectible--;

		//passer le collecible en floor
		mlx_xpm_file_to_image(game->mlx, "../xpm/grass.xpm", 16, 16);
		game->map[game->player.pos_y][game->player.pos_x] = 'O';
		mlx_xpm_file_to_image(game->mlx, "../xpm/steven.xpm", 16, 16);
	}
	if (game->player.pos_x - 1 == 'E')
	{
		if (game->collectible == 0)
			mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF0000, "Félicitations vous avez gagné");
	}

}
//game->collet --
//gerer le cas d'exit avec ft
//gerer les pas sur l'écran
// afficher le personnage nvll pos
//
