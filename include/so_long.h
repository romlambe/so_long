/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:33 by romlambe          #+#    #+#             */
/*   Updated: 2024/03/07 12:20:20 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# include <stdlib.h>
# include <stdio.h>

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

# define WINDOWS_WIDTH 700
# define WINDOWS_HEIGHT 700

# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

typedef struct s_axe
{
	int	x;
	int	y;
}				t_axe;

typedef struct s_player
{
	t_axe	p_pos;
	void	*player;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	char		*ber;
	char		*string;
	void		*end;
	int			count_p;
	int			count_c;
	int			count_e;
	int			check_exit;
	int			check_collectible;
	int			step_count;
	t_player	player;
	void		*floor;
	void		*collectible;
	void		*wall;
	void		*exit;
}	t_data;

int		main(int ac, char **av);
int		check_name_error(t_data *game);
int		check_wall(t_data *game);
int		check_square_map(t_data *game);
int		is_available_entity(t_data *game);
void	check_path(int x, int y, t_data *game, t_player *player);
void	init_image(t_data *game);
void	init_map(t_data *game, int i, int j);
void	create_window(t_data *game);
int		check_player(t_data *game);
int		check_collectible(t_data *game);
int		check_exit(t_data *game);
void	empty_map(t_data *game, const char *file);
void	read_map(t_data *game, const char *file);
void	alloc_map(t_data *game);
void	fill_map(t_data *game, const char *file);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strrncmp(char *s1, char *s2, int size);
int		hook_switch(int keycode, t_data *game);
int		check_all_error(t_data *game);
int		check_all_error_2(t_data *game);
void	move_up(t_player *player, t_data *game);
void	move_left(t_player *player, t_data *game);
void	move_right(t_player *player, t_data *game);
void	move_down(t_player *player, t_data *game);
void	free_sprites(t_data *game);
int		free_everything(t_data *game);
void	fill_path_map(t_data *game, t_player *player, const char *file);
char	**fill_map_temp(t_data *game, const char *file);
void	flood_fill(t_data *game, char **map, int x, int y);
void	print_step(int x, int y, t_data *game);

#endif
