# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 11:54:40 by atabarea          #+#    #+#              #
#    Updated: 2025/08/06 11:23:57 by atabarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/philosopher.c src/argnum_check.c src/struct_init.c src/ft_atol.c\
	src/checkargv.c src/philos_init.c src/philo_routine.c src/philo_actions.c\
	src/get_current_time.c src/left_or_right.c src/has_eaten.c src/isdead.c

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