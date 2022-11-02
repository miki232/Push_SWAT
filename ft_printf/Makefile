# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 12:28:21 by mtoia             #+#    #+#              #
#    Updated: 2022/11/02 17:05:38 by mardolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS			= $(SRCS:.c=.o)

NAME = ft_printf.a

CC = clang
FLAGS = -Wall -ggdb3
INC = ft_printf.h

T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

FILES			=	ft_printf.c utils/ft_hexa.c utils/ft_printnbr.c utils/ft_putchar.c utils/ft_putstr.c \
					utils/ft_uprint.c utils/ft_itoa.c utils/ft_ptr.c utils/ft_calloc.c utils/ft_bzero.c utils/ft_memset.c \
					
					
OBJ := $(FILES:%.c=%.o)

NB = $(words $(FILES))
IND = 0
PER = 0

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME):
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ... $(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been Compiled Successfully !$(C_END)"

clean:
	@rm -f $(OBJ) $(OBONUS)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_LMGN)➜ [$(NAME)] Library has been deleted Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette $(FILES) $(INC)
	@echo "[$(C_LGRN)➜ [$(NAME)] Files analized $(C_END)]"

.PHONY: clean fclean re all
