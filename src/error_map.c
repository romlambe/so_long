/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:26 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/28 17:44:02 by romlambe         ###   ########.fr       */
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

char	**fill_map_temp(t_data *game, const char *file)
{
	char **map_temp;
	int	fd;
	char *line;
	int	i;

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
			break;
		map_temp[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (map_temp);
}


void fill_path_map(t_data *game, t_player *player, const char *file)
{
	int	i;
	char **map_temp;

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



// check si c'est un .ber
// int	check_param(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (error_param());
// 	if (ft_strrncmp(av[1], ".ber", 4) != 0)
// 		return (error_param());
// }

