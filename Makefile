# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 18:25:59 by mtoia             #+#    #+#              #
#    Updated: 2022/11/02 17:49:01 by mardolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m
IND = 0
PER = 0

PRINTF = ft_printf/ft_printf.a

SRC = main.c src/utils.c src/split.c src/check.c src/push_moves.c src/rev_rot_moves.c src/rotate_moves.c \
		src/swap_moves.c src/aldo_ritmo.c src/small_sort.c src/check_chunk.c src/moves.c src/utils_sort.c \
		src/cin.c src/helpercin.c src/sortea.c src/cn_cin.c src/init.c src/free.c src/help_sortea.c

HDRS = include/

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -ggdb3

%.o: %.c 
	@$(CC) $(CFLAGS) -I $(HDRS) -c $< -o $@
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF)
	@make -C ft_printf/ 
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been Compiled Successfully !$(C_END)"

all: $(NAME)
	@make clean

clean:
	@rm -f $(OBJ)
	@echo "$(C_LGRN)➜ [$(NAME)] Objects has been Cleared Successfully !$(C_END)"

fclean:
	@rm -f $(NAME) $(OBJ)
	# @make -C check/ fclean
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been Cleared Successfully !$(C_END)"

norme:
	@norminette $(SRC)

re:
	@rm -f $(NAME) $(OBJ)
	@make  $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been re-Compiled Successfully !$(C_END)"

# bonus :
# 	make -C check/
# 	mv check/checker .

.PHONY: all clean  fclean  re 