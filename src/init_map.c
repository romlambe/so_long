/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:34:05 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/10 15:37:57 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_image(t_data *game)
{
	int	size;

	size = 16;
	game->floor = mlx_xpm_file_to_image(game->mlx, "../xpm/grass.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx, "../xpm/cobble.xpm", &size, &size);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "../xpm/diamond_on_grass.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "../xpm/portail.xpm", &size, &size);
	game->player.player = mlx_xpm_file_to_image(game->mlx, "../xpm/steve.xpm", &size, &size);


}

void	init_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] = 'P')
				mlx_put_image_to_window(game->mlx, game->win, &game->player.player, 16 * j, 16 *i);
			else if (game->map[i][j] = 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, j * 16, i * 16);
			else if (game->map[i][j] = 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 16, i * 16);
			else if (game->map[i][j] = '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, j * 16, i * 16);
			else if (game->map[i][j] = '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 16, i * 16);
			j++;
		}
		i++;
	}
}

void	create_window(t_data *game)
{
	
}
