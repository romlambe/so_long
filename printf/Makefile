# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 12:32:47 by romlambe          #+#    #+#              #
#    Updated: 2023/10/18 22:02:48 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_printf.c ft_printf_utils.c

NAME 		=	libftprintf.a

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

FLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
				ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(FLAGS) -o $@ -c $<

clean:
			$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
