/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:51:09 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 12:15:13 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hook_switch(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
		free_everything(game);
	else if (keycode == KEY_Z || keycode == KEY_UP)
		move_up(&game->player, game);
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		move_left(&game->player, game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(&game->player, game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(&game->player, game);
	return (0);
}

void	handle_end_of_game(int x, int y, t_data *game)
{
	if (game->map[y][x] == 'E' && game->count_c == 0)
		free_everything(game);
}

void	check_path(int x, int y, t_data *game, t_player *player)
{
	if (game->map[y][x] == 'C')
	{
		game->count_c--;
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			player->p_pos.x * 32, player->p_pos.y * 32);
		game->map[y][x] = 0;
	}
	handle_end_of_game(x, y, game);
	if (game->map[y][x] != '1' && game->map[y][x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			player->p_pos.x * 32, player->p_pos.y * 32);
		player->p_pos.x = x;
		player->p_pos.y = y;
		mlx_put_image_to_window(game->mlx, game->win, player->player,
			player->p_pos.x * 32, player->p_pos.y * 32);
		game->step_count++;
	}
	print_step(x, y, game);
	if (game->string)
	{
		free(game->string);
		game->string = NULL;
	}
}

void	print_step(int x, int y, t_data *game)
{
	game->string = ft_itoa(game->step_count);
	if (game->map[y][x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall, 64, 0);
		mlx_string_put(game->mlx, game->win, 0, 10, 0xFFFFFFFF, "nb de pas");
		mlx_string_put(game->mlx, game->win, 66, 10, 0xFFFFFFFF, game->string);
	}
}
