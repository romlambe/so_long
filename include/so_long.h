/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:33 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/10 15:29:44 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

#include <stdlib.h>
#include <stdio.h>

// # include "colors.h"
// define the windows
# define WINDOWS_WIDTH 700
# define WINDOWS_HEIGHT 700

// define the keys
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

typedef struct	s_axe
{
	int	x;
	int y;
}				t_axe;

typedef struct	s_player
{
	int	pos_x;
	int	pos_y;
	void *player;
}				t_player;

typedef	struct s_data
{
	void *mlx;
	void *win;
	char **map;
	int width;
	int height;
	char *ber;

	void *collectible;
	void *exit;
	// pour compter mes entités
	int count_p;
	int count_c;
	int count_e;
	// compter le nb de pas
	int step_count;
	t_player player;

	//
	void	*floor;
	void	*collectible;
	void	*wall;
	void	*exit;


}	t_data;


int main(int ac, char **av);

int	check_wall(t_data *game);
int	check_square_map(t_data *game);
int	is_available_entity(t_data *game);
int is_good(t_data *game);

int	ft_strcmp(char *s1, char c);
int	ft_strrncmp(char *s1, char *s2, int size);
int error_param();
int	check_param(int ac, char **av);

#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>

#endif

#endif
