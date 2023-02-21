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
CFLAGS				=	 -Wall -Werror -Wextra

INCLUDE		 		=	 inc/
LIB					=	 lib/

LIBFT_DIR			=	 $(LIB)Libft/
LIBFT				=	 $(LIBFT_DIR)libft.a

PRINTF_DIR			=	 $(LIB)Printf/
PRINTF				=	 $(PRINTF_DIR)libftprintf.a

MINILIBX_DIR		=	 $(LIB)Mlx/minilibx_macos/
MINILIBX			=	 $(MINILIBX_DIR)libmlx.a
MINILIBXCC			=	 -I mlx -L $(MINILIBX_DIR) -lmlx

HEADER 				=	 -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
OPENGL				=	 -framework OpenGL -framework AppKit
# **************************************************************************** #
# *********************************SOURCES************************************ #
SRC_FILES	=	fdf ft_utils ft_map get_next_line ft_line ft_mlx ft_point

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
# DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

# OBJF		=	.cache_exists
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
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(MINILIBX_DIR)
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBXCC) $(OPENGL)
#	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) $(HEADER) -o $@ -c $<
	@echo "$(CYAN)Compiling $<$(DEF_COLOR)"

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(NAME) objects deleted$(DEF_COLOR)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re