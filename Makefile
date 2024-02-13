# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:40:32 by romlambe          #+#    #+#              #
#    Updated: 2024/02/12 16:08:01 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX_PATH = minilibx-linux/libmlx.a
MLX_FILE = libmlx.a
MLX_FLAGS = -L/usr/X11R6/lib -lX11 -lXext

GET_NEXT_LINE = gnl/get_next_line.c gnl/get_next_line_utils.c
LIBFT_PATH = libft
LIBFT = libft/libft.a
PRINTF = printf/ft_printf.c printf/ft_printf_utils.c

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)
GET_NEXT_LINE_OBJ = $(GET_NEXT_LINE:.c=.o)
PRINTF_OBJ = $(PRINTF:.c=.o)
RM = rm - f

.SUFFIXES: .c .o

$(NAME): $(OBJ) $(GET_NEXT_LINE_OBJ) $(PRINTF_OBJ) $(LIBFT)
	make -C minilibx-linux/
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(GET_NEXT_LINE) $(PRINTF_OBJ) $(MLX_PATH) $(MLX_FLAGS) $(LIBFT) -o $(NAME) -I include/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I include/cl

all: $(NAME)

do_configure:
	@echo "Configuring minilibx..."
	@make -C minilibx-linux/ do_configure
	@echo "Minilibx configuration complete."

clean:
	@echo "Deleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC minilibx-linux/
	@echo "Done\n"
	@echo "Deleting So_long object...\n"
	@rm -f $(OBJ)
	@echo "Done\n"

fclean: clean
	@echo "Deleting so_long executable..."
	@rm -f $(NAME)
	@echo "Done\n"

re: fclean all

.PHONY: all do_configure clean fclean re
