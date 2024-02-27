/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:26 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/27 16:41:35 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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

// check si c'est un .ber
// int	check_param(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (error_param());
// 	if (ft_strrncmp(av[1], ".ber", 4) != 0)
// 		return (error_param());
// }

