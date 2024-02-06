/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:41:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/06 15:22:07 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700
# define MLX_ERROR 1
# define RED 0xFF0000
# define GREEN 0xFF00

#define KEY_ESC 65307


int handle_keypress(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return 0;
}

int render_rect(t_data *data)
{
	int i;
	int j;


	if (data->win_ptr == NULL)
		return 1;
	i = data->y;
	while(i < data->y + data->height)
	{
		j = data->x;
		while (j < data->x + data->height)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, data->color);
		i++;
	}
	return 0;
}

int render(t_data *data)
{
	data->x = WINDOW_HEIGHT - 100;
	data->y = WINDOW_WIDTH - 100;
	data->height = 100;
	data->width = 100;
	data->color = GREEN;
	render_rect(data);
	data->x = 0;
	data->y = 0;
	data->height = 100;
	data->width = 100;
	data->color = RED;
	render_rect(data);

	return 0;
}

int main(void)
{
	t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
    mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);

    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}



