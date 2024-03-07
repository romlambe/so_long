/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:18 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 12:13:26 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// ft pour savoir si la map est entourée de walls
int	check_wall(t_data *game)
{
	int	i;

	i = -1;
	while (game->map[0][++i])
		if (game->map[0][i] != '1' && game->map[0][i] != '\n')
			return (ft_printf("Error\n"), 1);
	i = -1;
	while (game->map[game->height - 1][++i])
	{
		if (game->map[game->height - 1][i] != '1'
			&& game->map[game->height - 1][i] != '\n')
			return (ft_printf("Error\n"), 1);
	}
	i = -1;
	while (++i < game->height - 1)
	{
		if (game->map[i][0] != '1')
			return (ft_printf("Error\n"), 1);
		if (game->map[i][game->width - 1] != '1'
			&& game->map[i][game->width - 1] != '\n'
				&& game->map[i][game->width - 1] != '\0')
			return (ft_printf("Error\n"), 1);
	}
	return (0);
}

int	check_square_map(t_data *game)
{
	int	i;
	int	start_len;
	int	len;

	i = 0;
	start_len = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		len = ft_strlen(game->map[i]);
		if (start_len != len)
			return (ft_printf("Error\n"), 1);
	}
	return (0);
}

int	is_available_entity(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'P'
					&& game->map[i][j] != 'C')
				return (ft_printf("Error\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_name_error(t_data *game)
{
	int	start_pos;
	int	size_ber;
	int	size_string;

	size_ber = ft_strlen(".ber");
	size_string = ft_strlen(game->ber);
	start_pos = size_string - size_ber;
	if (start_pos <= 0 || ft_strcmp(game->ber + start_pos, ".ber") != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
