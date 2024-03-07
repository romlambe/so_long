/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:42:35 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 11:55:55 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_y--;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0
		&& pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

void	move_down(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_y++;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0
		&& pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

void	move_left(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_x--;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0
		&& pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}

void	move_right(t_player *player, t_data *game)
{
	int	pos_temp_x;
	int	pos_temp_y;

	pos_temp_x = player->p_pos.x;
	pos_temp_y = player->p_pos.y;
	pos_temp_x++;
	if (pos_temp_x >= 0 && pos_temp_x < game->width && pos_temp_y >= 0
		&& pos_temp_y < game->height)
		check_path(pos_temp_x, pos_temp_y, game, player);
}
