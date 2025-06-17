# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 11:54:40 by atabarea          #+#    #+#              #
#    Updated: 2025/06/17 11:56:01 by atabarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosofers

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/philosofers.c src/argnum_check.c

OBJ = $(SRC:.c=.o)

INCLUDE = philosofers.h

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