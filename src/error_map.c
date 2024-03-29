/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:26 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 12:11:22 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**fill_map_temp(t_data *game, const char *file)
{
	char	**map_temp;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	map_temp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (map_temp == NULL)
		return (ft_printf("Error\n"), NULL);
	map_temp[game->height] = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n"), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_temp[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (map_temp);
}

void	fill_path_map(t_data *game, t_player *player, const char *file)
{
	int		i;
	char	**map_temp;

	i = 0;
	game->check_collectible = 0;
	game->check_exit = 0;
	map_temp = fill_map_temp(game, file);
	flood_fill(game, map_temp, player->p_pos.x, player->p_pos.y);
	if (game->check_collectible != game->count_c || game->check_exit == 0)
	{
		ft_printf("Error collectible or exit\n");
		while (map_temp[i])
		{
			free (map_temp[i]);
			i++;
		}
		free (map_temp);
		free_everything(game);
		exit (0);
	}
	while (map_temp[++i])
		free (map_temp[i]);
	free (map_temp);
}

void	flood_fill(t_data *game, char **map_temp, int x, int y)
{
	if (x <= 0 || y <= 0 || x > game->width || y > game->height)
		return ;
	if (map_temp[y][x] == '1' || map_temp[y][x] == 'X' ||
		map_temp[y][x] == 'V' || map_temp[y][x] == 'E')
	{
		if (map_temp[y][x] == 'E')
		{
			game->check_exit = 1;
			map_temp[y][x] = 'V';
		}
		return ;
	}
	if (map_temp[y][x] == 'C')
		game->check_collectible++;
	if (map_temp[y][x] != 'V')
		map_temp[y][x] = 'X';
	flood_fill(game, map_temp, x - 1, y);
	flood_fill(game, map_temp, x + 1, y);
	flood_fill(game, map_temp, x, y - 1);
	flood_fill(game, map_temp, x, y + 1);
}
