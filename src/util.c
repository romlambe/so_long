/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:07:42 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 12:07:43 by romlambe         ###   ########.fr       */
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
