/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:41:19 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/28 17:50:56 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	empty_map(t_data *game, const char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		game->map = NULL;
		ft_printf("Error\n");
		free_everything(game);
	}
	if (read(fd, &c, 1) == 0)
	{
		game->map = NULL;
		ft_printf("Error\n");
		close(fd);
		free_everything(game);
	}
}

void	read_map(t_data *game, const char *file)
{
	int		fd;
	char	*line;

	game->width = 0;
	game->height = 0;
	empty_map(game, game->ber);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (game->height == 0)
			game->width = ft_strlen(line) - 1;
		game->height++;
		free(line);
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
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
}
