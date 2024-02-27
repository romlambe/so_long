/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:28:18 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/27 15:41:34 by romlambe         ###   ########.fr       */
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
			return(ft_printf("Error\n"), 1);
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

// ft pour savoir si la map est bien rectangulaire
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
		while(game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'P'
					&& game->map[i][j] != 'C')
				return (ft_printf("Error"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

// si la map est correctement remplie
// changer la ft car faire la boucle pour la map entiere
// int	is_available_entity(t_data *game)
// {
// 	char	charset[] = {'0', '1', 'P', 'E', 'C'} ;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	// charset[0] = ;
// 	while (charset[i])
// 	{
// 		if (game->map[i][j] != charset[i])
// 			error_param();
// 		i++;
// 	}
// 	return (0);
// }



