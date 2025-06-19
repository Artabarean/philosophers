# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 11:54:40 by atabarea          #+#    #+#              #
#    Updated: 2025/06/19 10:22:12 by atabarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/philosophers.c src/argnum_check.c src/struct_init.c src/ft_atol.c\
	src/checkargv.c src/philos_init.c

OBJ = $(SRC:.c=.o)

INCLUDE = philosophers.h

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re