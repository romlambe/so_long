/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:41:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/28 14:30:26 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	check_all_error(t_data *game)
{
	int	error;

	read_map(game, game->ber);
	alloc_map(game);
	fill_map(game, game->ber);
	error = check_name_error(game);
	if (error == 1)
		return (1);
	error = check_wall(game);
	if (error == 1)
		return (1);
	error = check_square_map(game);
	if (error == 1)
		return (1);
	error = is_available_entity(game);
	if (error == 1)
		return (1);
	error = check_player(game);
	if (error == 1)
		return (1);
	error = check_collectible(game);
	if (error == 1)
		return (1);
	error = check_exit(game);
	if (error == 1)
		return (1);
	fill_path_map(game, &game->player, game->ber);
	return (0);
}

int main(int ac, char **av)
{
	t_data game;

	if (ac != 2)
		return (ft_printf("Error\n"), 1);
	game.ber = ft_strdup(av[1]);
	if (game.ber == NULL)
		return (1);
	game.mlx = mlx_init();
	game.win = NULL;
	init_image(&game);
	if (check_all_error(&game) == 1)
		free_everything(&game);
	create_window(&game);
	check_player(&game);
	mlx_loop(game.mlx);
	return 0;
}


//7)check si la map est faisable (sortie et collectibles accessibles)
//gerer les erreurs: nom de la map, wall, carre, si les chars sont les bons
//flood fill pour savoir si la map est ok
//si map vide ou non faisable tout free
