HEADER = ft_printf.h

# ##################
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
# ##################

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c libft_printf.c

OBJ = ${SRC:%.c=%.o}

%.o : %.c ${HEADER} Makefile
	gcc ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	ar crs ${NAME} ${OBJ}
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
	rm -rf ${OBJ}
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	rm -rf ${NAME}
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all ${NAME} clean fclean re
