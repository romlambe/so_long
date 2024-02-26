/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:41:19 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/13 13:54:39 by romlambe         ###   ########.fr       */
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
		ft_printf("Error map\n");
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		// printf("%s", line);
		if (line == NULL)
			break;
		if (game->height == 0)
			game->width = ft_strlen(line) - 1;
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
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
		return ;
	game->map[game->height] = NULL;

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
		ft_printf("Error fill map\n");
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		game->map[i] = ft_strdup(line);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
}
