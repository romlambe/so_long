/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:34:05 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/13 11:55:15 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



void	init_image(t_data *game)
{
	int	size;

	size = 32;
	game->floor = mlx_xpm_file_to_image(game->mlx, "./xpm/New-Project.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./xpm/cobble.xpm", &size, &size);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./xpm/diamond_on_grass.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./xpm/portail.xpm", &size, &size);
	game->player.player = mlx_xpm_file_to_image(game->mlx, "./xpm/steve.xpm", &size, &size);


}

void	init_map(t_data *game, int i, int j)
{
	int size;

	size = 32;
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.player, j * size, i * size);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, j * size, i * size);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j * size, i * size);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, j * size, i * size);
			else if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * size, i * size);
			}
			j++;
		}
		i++;
	}
}

void	create_window(t_data *game)
{
	read_map(game, game->ber);
	alloc_map(game);
	fill_map(game, game->ber);
	if (game->mlx == NULL)
		return ;
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "So_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		return ;
	}
		init_map(game, 0, 0);
	mlx_hook(game->win, 2, 1<<0, &hook_switch, game);
	// mlx_hook(game->win, 17, (1L<<0), &free_everything, game);
	mlx_loop(game->mlx);
}
