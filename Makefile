# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 18:25:59 by mtoia             #+#    #+#              #
#    Updated: 2022/10/14 18:30:08 by mtoia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c utils.c split.c 

HDRS = /

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

%.o: %.c 
	@$(CC) $(CFLAGS) -I {HDRS} -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)
	make clean

clean:
	rm -f $(OBJ)
	@echo "PUULIIIIIITOOOOOOO"

fclean:
	rm -f $(NAME) $(OBJ)
	@echo "TUTTOOOO PULITOOO"

re: fclean $(NAME)

.PHONY: all clean fclean re