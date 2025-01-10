
NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra

MAKE_NOPRINT = ${MAKE} --no-print-directory
HEADER = ./includes/
SRC = src/ft_printf.c src/ft_printf_utils.c

OBJ = ${SRC:%.c=%.o}
LIBS_PATH = ./lib/

all: libft ${NAME}

${NAME}: ${OBJ} ${LIBS_PATH}libft.a
	cp ${LIBS_PATH}libft.a ${NAME}
	ar rcs ${NAME} ${OBJ}


bonus: all

libft:
	cd ${LIBS_PATH} && ${MAKE_NOPRINT}


clean:
	rm -f ${OBJ}
	cd ${LIBS_PATH} && ${MAKE_NOPRINT} $@

fclean: clean
	rm -f ${NAME}
	cd ${LIBS_PATH} && ${MAKE_NOPRINT} $@

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

re: fclean all

.PHONY: all clean fclean re