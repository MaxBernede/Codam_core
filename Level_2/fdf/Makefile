# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kyuuh <kyuuh@student.42.fr>                  +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/07 10:45:43 by mbernede      #+#    #+#                  #
#    Updated: 2023/11/02 19:58:03 by maxb          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME	:=		fdf

SRCS 	:= 		main.c\
				hook.c\
				utils.c\
				second.c\
				grid.c\
				mapvalues.c\
				colorpoint.c\
				utils2.c\

RM 		:= 		rm -f
CFLAGS	:=		-Wall -Werror -Wextra
CC		:= 		cc

OBJ_DIR	:=		./objs/
SRC_DIR	:=		./srcs/

LIBA	:=	libft/libft.a

LIBMLX	:=	MLX42/libmlx42.a
# MLXFLAG	:=	-I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
#MLXFLAG	:=	-ldl -lglfw -lm -pthread -I MLX42/include

OS		:= -I ./MLX42

ifdef DEBUG
	OS += -g -fsanitize=address
endif

ifdef LINUX
	OS += -ldl -lglfw -lm -pthread
endif

ifndef LINUX
	OS += -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib" -framework Cocoa -framework OpenGL -framework IOKit
endif

OBJ 	:= 		$(addprefix ${OBJ_DIR},${SRCS:.c=.o})

${NAME}:	${OBJ}
	@make -C MLX42
	@make -C libft
	$(CC) -o $@ $^ $(LIBA) $(LIBMLX) $(OS) 
	@echo "$(GREEN)$(BOLD)FDF Done$(RESET)"

all : ${NAME}

${OBJ_DIR}%.o:	${SRC_DIR}%.c fdf.h
	@echo "$(GREEN)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@${CC} ${CFLAGS} -o $@ -c $<

clean:
	@make -C MLX42 clean
	@make -C libft clean
	@${RM} ${OBJ}
	@echo "$(RED)Cleaning FDF$(RESET)"

fclean: 	clean
	@make -C libft fclean
	@make -C MLX42 fclean
	@${RM} ${NAME}
	@echo "$(RED)Full clean done$(RESET)"

re: 	fclean all

.PHONY:		all clean fclean re
