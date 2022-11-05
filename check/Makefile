# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 16:19:49 by mtoia             #+#    #+#              #
#    Updated: 2022/11/05 11:55:17 by mardolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

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

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c checker.c check.c utils.c \
		push_moves.c rev_rot_moves.c rotate_moves.c swap_moves.c utils_n.c checker_utils.c print_error.c

HDRS = checker.c


OBJ = $(SRC:.c=.o)



CC = gcc
CFLAGS = -Wall -Werror -Wextra

%.o: %.c 
	@$(CC) $(CFLAGS) -I {HDRS} -c $< -o $@
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been Compiled Successfully !$(C_END)"

all: $(NAME)
	make clean

clean:
	@rm -f $(OBJ)
	@echo "$(C_LGRN)➜ [$(NAME)] Objects has been Cleared Successfully !$(C_END)"

fclean:
	@rm -f $(NAME) $(OBJ)
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been Cleared Successfully !$(C_END)"

norme:
	@norminette $(SRC)

re:
	@rm -f $(NAME) $(OBJ)
	@make  $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Program has been re-Compiled Successfully !$(C_END)"

.PHONY: all clean  fclean  re 