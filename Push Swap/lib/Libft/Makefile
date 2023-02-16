DEF_COLOR = \033[1;39m
WHITE = \033[1m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CIAN = \033[1;36m

NAME = libft.a

HEADER = libft.h

BNAME = .bonus

SRC		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
			ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_striteri.c \
			ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c

SRC_B	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c	ft_lstiter_bonus.c ft_lstmap_bonus.c

FLAGS = -Wall -Werror -Wextra

OBJ = ${SRC:%.c=%.o}

OBJ_B = ${SRC_B:%.c=%.o}

%.o : %.c ${HEADER} Makefile
	@printf "${PINK}\rCompiling: ${YELLOW}$<...${DEF_COLOR}				\r"
	@gcc ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	@ar crs ${NAME} ${OBJ}
	@echo "$(GREEN)libft library has been created!$(DEF_COLOR)"

all: ${NAME}

bonus: ${BNAME}

${BNAME}: ${OBJ} ${OBJ_B}
	@ar crs ${NAME} ${OBJ} ${OBJ_B}
	@touch $@
	@echo "$(GREEN)libft library has been created!$(DEF_COLOR)"

clean:
	@rm -f ${OBJ} ${OBJ_B}
	@echo "$(RED)libft objects deleted$(DEF_COLOR)"

fclean: clean
	@rm -f ${NAME} ${BNAME}
	@echo "$(RED)libft deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(YELLOW)libft recompiled$(DEF_COLOR)"

.PHONY: all bonus clean fclean re