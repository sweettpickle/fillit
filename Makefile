# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scash <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 19:06:17 by scash             #+#    #+#              #
#    Updated: 2019/11/06 19:13:03 by cdoreah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fillit

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			= check_errors.c main.c ft_square.c ft_tetriminos.c ft_struct.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS)))



all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
