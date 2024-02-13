/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:41:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/12 16:24:27 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	check_all_error(t_data *game)
{
	int	error;

	read_map(game, game->ber);
	alloc_map(game);
	fill_map(game, game->ber);
	error = check_wall(game);
	if (error == 1)
		error_param();
	error = check_square_map(game);
	if (error == 1)
		error_param();
	error = is_available_entity(game);
	if (error == 1)
		error_param();
	error = check_player(game);
	if (error == 1)
		error_param();
	error = check_collectible(game);
	if (error == 1)
		error_param();
	error = check_exit(game);
	if (error == 1)
		error_param();
	// gerer les parametres de la fonction
	// error = check_param(ac, **av);
	// if (error == 1)
	// 	error_param();
	return (0);
}

int main(int ac, char **av)
{
	t_data game;

	if (ac != 2)
	{
		error_param();
		return (1);
	}
	game.ber = (char *)malloc(ft_strlen(av[1]) * sizeof(char));
	if (game.ber == NULL)
		return (1);
	game.ber = ft_strdup(av[1]);
	game.mlx = NULL;
	if (check_all_error(&game) == 0)
		create_window(&game);
	return 0;
}
