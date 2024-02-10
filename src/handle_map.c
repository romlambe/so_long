/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:41:19 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/10 15:41:59 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(t_data *game, const char *file)
{
	int		fd;
	char	*line;

	game->width = 0;
	game->height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		return ;
	}
	while (line = get_next_line(fd))
	{
		if (game->height == 0)
			game->width = ft_strlen(line - 1);
		game->height++;
	}
	close(fd);
}

void	alloc_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map = (char **)malloc(sizeof(char *) * game->height);
	if (game->map == NULL)
		return ;
	while (i <= game->height)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->width) + 1);
		if (game->map[i] == NULL)
		{
			while(j < i)
			{
				free(game->map[j]);
				j++;
			}
			free(game->map);
			return ;
		}
		i++;
	}
}

void	fill_map(t_data *game, const char *file)
{
	int	fd;
	char *line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		return ;
	}
	while (line = get_next_line(fd))
	{
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
}
