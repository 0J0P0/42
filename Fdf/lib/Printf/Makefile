# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:48:21 by jzaldiva          #+#    #+#              #
#    Updated: 2023/02/04 19:48:21 by jzaldiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
DEF_COLOR	=	\033[1;39m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;30m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PINK		=	\033[1;35m
CIAN		=	\033[1;36m
# 																			   #
# **************************************************************************** #
# 																			   #
NAME = libftprintf.a
HEADER = ft_printf.h


SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE = ./inc/

FILES = ft_printf ft_printf_utils

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

FLAGS = -Wall -Werror -Wextra
# 																			   #
# **************************************************************************** #
# 																			   #
${OBJ_DIR}%.o : ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	@gcc ${FLAGS} -I./ -c $< -o $@
	@printf "${PINK}\rCompiling: ${YELLOW}$<...${DEF_COLOR}				\r"

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDE}${HEADER}
	@ar crs ${NAME} ${OBJ}
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)"

clean:
	@rm -rf ${OBJ_DIR}
	@echo "$(RED)Printf objects deleted$(DEF_COLOR)"

fclean: clean
	@rm -rf ${NAME}
	@echo "$(RED)Printf deleted$(DEF_COLOR)"

re: fclean all

.PHONY: all ${NAME} clean fclean re