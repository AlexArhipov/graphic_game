NAME	=	cub3D

SRCS	=	srcs/draw/*.c srcs/monstr/*.c srcs/move/*.c srcs/bonus/*.c\
		srcs/valid/*.c srcs/st_gm/*.c

HEADER	=	srcs/header/

LIBA	=   srcs/libft/libft.a

LIBM	=   srcs/minilibx/libmlx.a

GCC				= gcc

RM				= rm -f

CFLAGS	=	-Wall -Werror -Wextra -I ${HEADER} -framework OpenGL -framework Appkit

all:	${NAME}

${NAME}: ${LIBA} ${LIBM} ${SRCS}
	${GCC} ${CFLAGS} ${SRCS} ${LIBA} ${LIBM} -o ${NAME}

${LIBA}:
	make -C srcs/libft
${LIBM}:
	make -C srcs/minilibx
clean:
	make fclean -C ./srcs/libft/
	make clean -C ./srcs/minilibx
fclean:	clean
		${RM} ${NAME}

re:			fclean all
