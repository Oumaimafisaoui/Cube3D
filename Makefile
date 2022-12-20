CC = cc
RM = rm -rf
XFLAGS = -Wall -Wextra -Werror  -Imlx -fsanitize=address -g

SRC =  main.c cub3d_outils.c draw_minimap.c init.c move_player.c
OBJ = ${SRC:.c=.o}
NAME = cub3d
LIB  = header.h

all : ${NAME}

${NAME} : ${OBJ} ${LIB}
		${CC} -g ${XFLAGS} ${OBJ}  -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o : %.c ${LIB}
	${CC} -g ${XFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM}  ${NAME}

re: fclean all

.PHONY: clean fclean re all