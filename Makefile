# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:40:32 by romlambe          #+#    #+#              #
#    Updated: 2024/03/07 12:08:51 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLX_PATH = minilibx-linux/libmlx.a
MLX_FILE = libmlx.a
MLX_FLAGS = -L/usr/X11R6/lib -lX11 -lXext


SRC = src/check_count.c src/check_map.c src/error_map.c src/free.c \
src/handle_map.c src/init_map.c src/main.c src/moves.c src/manage_moves.c \
src/util.c
GET_NEXT_LINE = gnl/get_next_line.c gnl/get_next_line_utils.c
PRINTF = printf/ft_printf.c printf/ft_printf_utils.c
LIBFT = libft/libft.a


OBJ = $(SRC:.c=.o)
GET_NEXT_LINE_OBJ = $(GET_NEXT_LINE:.c=.o)
PRINTF_OBJ = $(PRINTF:.c=.o)
RM = rm -f

all: romlambe project $(NAME)

romlambe:
	@echo "Author: romlambe"

project:
	@echo "Project: So_long"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(GET_NEXT_LINE_OBJ) $(PRINTF_OBJ) $(LIBFT)
	make -C minilibx-linux/
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(GET_NEXT_LINE) $(PRINTF_OBJ) $(MLX_PATH) $(MLX_FLAGS) $(LIBFT) -o $(NAME) -I include/



all: $(NAME)

do_configure:
	@echo "Configuring minilibx..."
	@make -C minilibx-linux/ do_configure
	@echo "Minilibx configuration complete."

clean:
	$(RM) $(OBJ)
	$(RM) $(PRINTF_OBJ)
	$(RM) $(GET_NEXT_LINE_OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: author fclean all

.PHONY: all do_configure clean fclean re
