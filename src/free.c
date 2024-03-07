/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:11:57 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 12:06:39 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_sprites(t_data *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->player.player)
		mlx_destroy_image(game->mlx, game->player.player);
}

int	free_everything(t_data *game)
{
	int	i;

	i = -1;
	if (game->map != NULL)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	free_sprites(game);
	free(game->ber);
	if (game->win != NULL)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}
