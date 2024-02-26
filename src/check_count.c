/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:26:57 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/26 18:47:59 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_player(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->height)
	{
		j = 0;
		while(j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player.p_pos.x = j;
				game->player.p_pos.y = i;
				game->count_p++;
			}
			j++;
		}
		i++;
	}
	if (game->count_p != 1)
	{
		ft_printf("Error player\n");
		return (1);
	}
	return 0;
}

int	check_collectible(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if(game->map[i][j] == 'C')
			{
				game->count_c++;
			}
			j++;
		}
		i++;
	}
	if (game->count_c < 1)
	{
		ft_printf("Error collectible\n");
		return (1);
	}
	return (0);
}

int	check_exit(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E')
			{
				game->count_e++;
			}
			j++;
		}
		i++;
	}
	if (game->count_e != 1)
	{
		ft_printf("Error exit\n");
		return (1);
	}
	return (0);
}
