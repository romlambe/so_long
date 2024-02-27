/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:26:57 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/27 15:44:37 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_player(t_data *game)
{
	int	i;
	int	j;
	game->count_p = 0;

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
		return (ft_printf("Error\n"), 1);
	return 0;
}

int	check_collectible(t_data *game)
{
	int	i;
	int	j;

	game->count_c = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if(game->map[i][j] == 'C')
				game->count_c++;
			j++;
		}
		i++;
	}
	if (game->count_c < 1)
		return (ft_printf("Error\n"), 1);
	return (0);
}

int	check_exit(t_data *game)
{
	int	i;
	int	j;

	game->count_e = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E')
				game->count_e++;
			j++;
		}
		i++;
	}
	if (game->count_e != 1)
		return (ft_printf("Error\n"), 1);
	return (0);
}
