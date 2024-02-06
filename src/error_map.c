/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:26 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/06 15:30:06 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strrncmp(char *s1, char *s2, int size)
{
	int	i;
	int	count;

	i = ft_strlen(s1 - 1);
	count = 0;
	while (s1[i] && s1[i] == s2[i] && count < size)
	{
		i--;
		count ++;
	}
	return (s1 - s2);
}
int error_param(char *msg)
{
	ft_printf("Error\n ");
	return (0);
}

// check si c'est un .ber
int	check_param(int ac, char **av)
{
	if (ac != 2)
		return (error_param("arguments"));
	if (ft_strrncmp(av[1], ".ber", 4) != 0)
		return (error_param("need avalaible map"));
}
// ft pour savoir si la map est entourée de walls
int	check_wall(t_data *game)
{
	int	i;
	int	start;
	int end;

	if (!**game->map)
		return (0);
	if (ft_strcmp(game->map[0], 1) != 0) // faire la ft pour les comparer
		return (0);
	i = 1;
	while(game->map[i - 1])
	{
		start = game->map[i][0];
		end = game->map[i][ft_strlen(game->map[i])];
		if (start == 1 && end == 1)
			i++;
		else
			return (0);
	}
	if (ft_strcmp(game->map[i + 1] != 0))
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
			return 0;
		i++;
	}
}

// si la map est correctement rempli

int	is_available_entity(char c)
{
	char	charset[6];
	int		i;

	i = 0;
	charset[6] = "0, 1, P, E, C";
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}


//compter et regarder si j'ai le bon nb de chaque entitée
int is_good(t_data *game)
{
	game->i = 0;
	game->j = 0;

	while(game->map[game->i])
	{
		while(game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'E')
				game->count_e += 1;
			if (game->map[game->i][game->j] == 'P')
				game->count_p += 1;
			if (game->map[game->i][game->j] == 'C')
				game->count_c += 1;
			game->j++;
		}
		game->i++;
	}
	if (game->count_e != 1 && game->count_p != 1 && game->count_c < 1)
		return (1);
	return (0);
}
