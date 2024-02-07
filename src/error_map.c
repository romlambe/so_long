/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:26 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/06 17:29:21 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strcmp(char *s1, char c)
{
	int	i;

	i = 0;
	while(s1[i])
	{
		if (s1[i] != c)
			return (1);
		i++;
	}
	return (0);
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
int error_param()
{
	ft_printf("Error\n ");
	return (1);
}

// check si c'est un .ber
int	check_param(int ac, char **av)
{
	if (ac != 2)
		return (error_param());
	if (ft_strrncmp(av[1], ".ber", 4) != 0)
		return (error_param());
}

