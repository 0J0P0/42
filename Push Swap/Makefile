# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:50:40 by jzaldiva          #+#    #+#              #
#    Updated: 2023/01/27 16:50:40 by jzaldiva         ###   ########.fr        #
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
# ******************************** FILES ************************************* #

NAME = push_swap
CHECK = check

LIB 	= lib/
LIBFT	= $(LIB)Libft/libft.a

PRINTF = $(LIB)/Printf/libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE	= inc/

SRC_FILES	=	push_swap ft_moves ft_valid_parameters
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
# **************************************************************************** #
# ******************************* COMMANDS *********************************** #
CFLAGS = -Wall -Wextra -Werror
# **************************************************************************** #
# ********************************* RULES ************************************ #
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "$(CIAN)$@ object created$(DEF_COLOR)"

$(LIBFT):
	@make -C $(LIB)Libft

$(PRINTF):
	@make -C $(LIB)Printf

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB)Libft clean
	@make -C $(LIB)Printf clean
	@echo "$(RED)$(NAME) objects deleted$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB)Libft fclean
	@make -C $(LIB)Printf fclean
	@echo "$(RED)$(NAME) deleted$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re