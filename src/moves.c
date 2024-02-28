/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:42:35 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/28 16:08:59 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hook_switch(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
		free_everything(game);
	else if (keycode == KEY_Z || keycode == KEY_UP)
	{
		move_up(&game->player, game);
	}
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
		mlx_put_image_to_window(game->mlx, game->win, game->floor, player->p_pos.x * 32, player->p_pos.y * 32);
		game->map[y][x] = 0;
	}
	handle_end_of_game(x, y, game);
	if (game->map[y][x] != '1' && game->map[y][x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, player->p_pos.x * 32, player->p_pos.y * 32);
		player->p_pos.x = x;
		player->p_pos.y = y;
		mlx_put_image_to_window(game->mlx, game->win, player->player, player->p_pos.x * 32, player->p_pos.y* 32);
		game->step_count++;
	}
	print_step(x, y ,game);
}

void print_step(int x, int y, t_data *game)
{
	game->string = ft_itoa(game->step_count);
	if (game->map[y][x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall, 64, 0);
		mlx_string_put(game->mlx, game->win, 0, 10, 0xFFFFFFFF, "nb de pas");
		mlx_string_put(game->mlx, game->win, 66, 10, 0xFFFFFFFF, game->string);
	}
}

void	move_up(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_y--;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0 && pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

void	move_down(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_y++;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0 && pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

void	move_left(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_x--;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0 && pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

void	move_right(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_x++;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0 && pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

