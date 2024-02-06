/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:33 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/06 15:21:50 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"

#include <stdlib.h>
#include <stdio.h>

// # include "colors.h"

typedef	struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	char **map;
	int	x;
	int	y;
	int width;
	int height;
	int color;
	// pour compter mes entités
	int count_p;
	int count_c;
	int count_e;
	int i;
	int j;
}	t_data;

int handle_keypress(int keysym, t_data *data);
int render(t_data *data);
int main(void);

#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>

#endif

#endif
