# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 16:02:08 by jzaldiva          #+#    #+#              #
#    Updated: 2023/01/29 16:02:08 by jzaldiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************VARIABLES********************************** #
NAME				=	 fdf

SRC_DIR				=	 src/
OBJ_DIR				=	 obj/
CC					=	 gcc
CFLAGS				=	 -g -O3 -Wall -Werror -Wextra

INC		 			=	 inc/
LIB					=	 lib/

LIBFT_DIR			=	 $(LIB)libft/
LIBFT				=	 $(LIBFT_DIR)libft.a

PRINTF_DIR			=	 $(LIB)Printf/
PRINTF				=	 $(PRINTF_DIR)libftprintf.a

MINILIBX_DIR		=	 $(LIB)minilibx/minilibx_macos/
MINILIBX			=	 $(MINILIBX_DIR)libmlx.a
MINILIBXCC			=	 -I mlx -L $(MINILIBX_DIR) -lmlx

HEADER 				=	 -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
OPENGL				=	 -framework OpenGL -framework AppKit

SRC_FILES	=	main

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists
# **************************************************************************** #
# *********************************COLORS************************************* #
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
# **********************************RULES************************************* #
all: makelibs
	@$(MAKE) $(NAME)

makelibs:	
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)

-include 	${DEPS}
$(NAME): $(OBJ)		
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MINILIBXCC) $(OPENGL) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)" 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
	$(CC) $(CFLAGS) -MMD -c $< -o $@
	@printf "${CYAN}\rCompiling: ${YELLOW}$<...${DEF_COLOR}				\r"

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)Printf compiled!$(DEF_COLOR)"	

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"			

clean:
	@make clean -sC $(PRINTF_DIR)
	@make clean -C $(MINILIBX_DIR)
	$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)object files cleaned!$(DEF_COLOR)"

fclean:	clean
	$(RM) -f $(NAME)
	$(RM) -f $(MINILIBX_DIR)libmlx.a
	$(RM) -f $(LIBFT_DIR)libft.a
	@echo "$(RED)$(NAME) deleted$(DEF_COLOR)"

re: fclean all	

.PHONY:		all clean fclean re
