# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 14:42:49 by jzaldiva          #+#    #+#              #
#    Updated: 2023/02/07 14:42:49 by jzaldiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ****************************** COLORS ************************************** #
DEF_COLOR	=	\033[1;39m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;30m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PINK		=	\033[1;35m
CIAN		=	\033[1;36m
# **************************************************************************** #
# ********************************* VARIABLES ******************************** #
NAME = pipex

LIB 	= lib/
LIBFT	= $(LIB)Libft/libft.a
PRINTF 	= $(LIB)/Printf/libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE	= inc/

SRC_FILES	=	pipex
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
# **************************************************************************** #
# ******************************* COMMANDS *********************************** #
CFLAGS = -Wall -Wextra -Werror
# **************************************************************************** #
# ********************************* RULES ************************************ #
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)Libft
	@make -C $(LIB)Printf
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "$(CIAN)Compiling $<$(DEF_COLOR)"

clean:
	@make clean -C $(LIB)Libft
	@make clean -C $(LIB)Printf
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(NAME) objects deleted$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIB)Libft
	@make fclean -C $(LIB)Printf
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
