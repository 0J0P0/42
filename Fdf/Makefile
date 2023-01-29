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
	@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"
	@echo "$(GREEN)✨ FDF compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
	@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"	

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"			

clean:
	@make clean -sC $(PRINTF_DIR)
	@echo "$(CYAN)ft_printf object and dependency files cleaned.$(DEF_COLOR)"
	@make clean -C $(MINILIBX_DIR)
	@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
	$(RM) -rf $(OBJ_DIR)
	@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:	clean
	$(RM) -f $(NAME)
	@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
	$(RM) -f $(MINILIBX_DIR)libmlx.a
	@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
	$(RM) -f $(LIBFT_DIR)libft.a
	@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"

re: fclean 
		@$(MAKE)	
		@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

.PHONY:		all clean fclean re
