/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:18 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/10 15:36:03 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// ft pour savoir si la map est entourée de walls
int	check_wall(t_data *game)
{
	int	i;
	int	start;
	int end;

	if (!(game->map))
		return (1);
	if (ft_strcmp(game->map[0], 1) != 0)
		return (1);
	i = 1;
	while(game->map[i - 1])
	{
		start = game->map[i][0];
		end = game->map[i][ft_strlen(game->map[i])];
		if (start == 1 && end == 1)
			i++;
		else
			return (1);
	}
	if (ft_strcmp(game->map[i + 1], 1)!= 0)
		error_param();
	return (0);
}
// ft pour savoir si la map est bien rectangulaire
int	check_square_map(t_data *game)
{
	int		i;
	int		len;

	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len != ft_strlen(game->map[i + 1]))
			error_param();
		i++;
	}
	return (0);
}

// si la map est correctement remplie
// changer la ft car faire la boucle pour la map entiere
int	is_available_entity(t_data *game)
{
	char	charset[6];
	int		i;
	int		j;

	i = 0;
	charset[6] = "0, 1, P, E, C";
	while (charset[i])
	{
		if (game->map[i][j] != charset[i])
			error_param();
		i++;
	}
	return (0);
}



