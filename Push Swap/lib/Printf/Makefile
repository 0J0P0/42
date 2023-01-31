HEADER = ft_printf.h
# ##################
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
PINK = \033[1;35m
# ##################

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE = ./inc/

FILES = ft_printf ft_printf_utils

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

${OBJ_DIR}%.o : ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	@gcc ${FLAGS} -I./ -c $< -o $@
	@echo "$(PINK)Compiling $<$(DEF_COLOR)"
all: ${NAME}

${NAME}: ${OBJ} ${INCLUDE}${HEADER}
	@ar crs ${NAME} ${OBJ}
	@echo "$(GREEN)ft_printf library has been created!$(DEF_COLOR)"

clean:
	@rm -rf ${OBJ_DIR}
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -rf ${NAME}
	@echo "$(CYAN)ft_printf library executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all ${NAME} clean fclean re