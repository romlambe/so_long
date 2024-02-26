/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:41:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/26 18:52:11 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	check_all_error(t_data *game)
{
	int	error;

	// error = check_wall(game);
	// if (error == 1)
	// 	error_param();
	// error = check_square_map(game);
	// if (error == 1)
	// 	error_param();
	// // error = is_available_entity(game);
	// // if (error == 1)
	// 	error_param();
	error = check_player(game);
	if (error == 1)
		error_param();
	// error = check_collectible(game);
	// if (error == 1)
	// 	error_param();
	// error = check_exit(game);
	// if (error == 1)
	// 	error_param();
	// // gerer les parametres de la fonction
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
	game.ber = ft_strdup(av[1]);
	if (game.ber == NULL)
		return (1);
	game.mlx = mlx_init();

	game.win = NULL;
	init_image(&game);

	// if (check_all_error(&game) == 1)
	// {
	// 	mlx_destroy_window(game.mlx, game.win);
	// 	game.mlx = NULL;
	// 	return (0);
	// }
	create_window(&game);
	check_player(&game);
	mlx_loop(game.mlx);
	return 0;
}


//mettre les ft init maps dans les erreurs pour initialiser la taille witdh et height
//avoir la position du joueur pour ensuite le faire se deplacer
//gerer les erreurs: nom de la map, wall, carre, si les chars sont les bons
//cheker les counts de joueurs, collectibles, exit
