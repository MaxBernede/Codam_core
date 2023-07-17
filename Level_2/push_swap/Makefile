# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kyuuh <kyuuh@student.42.fr>                  +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/13 01:44:09 by kyuuh         #+#    #+#                  #
#    Updated: 2023/02/02 19:38:45 by mbernede      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

BON_NAME := checker

SRCS =  pivottemp.c\
		pushswap.c\
		quicksort.c\
		rotas.c\
		revrota.c\
		smolsort.c\
		swappush.c\
		utils.c\
		utils2.c\
		utils3.c\

BONUS = bonus_start.c\
		rotas.c\
		revrota.c\
		swappush.c\
		utils.c\
		utils2.c

CC = cc

LIBA	:=	libft/libft.a
LIBH	:=	libft/libft.h

FLAGS = -Wall -Wextra -Werror

OBJ_DIR	:=		./objs/
SRC_DIR :=		./srcs/

OBJ 	:= 		$(addprefix ${OBJ_DIR},${SRCS:.c=.o})

BON		:=		$(addprefix ${OBJ_DIR},${BONUS:.c=.o})

${NAME}:	${OBJ}
	@make -C libft
	@$(CC) -o $@ $^ $(LIBA)
	@echo "SUCCESS"

${BON_NAME}:	${BON}
	@make -C libft
	@$(CC) -o $@ $^ $(LIBA)
	@echo "SUCCESS"

all : $(NAME)

bonus : $(BON_NAME)

${OBJ_DIR}%.o:	${SRC_DIR}%.c $(LIBH)
	@${CC} ${CFLAGS} -o $@ -c $<

clean: 
	@make -C libft clean
	@${RM} ${OBJ} ${BON}
	@echo "test cleaned"

fclean: 	clean
	@make -C libft fclean
	@${RM} ${NAME} ${BON_NAME}

re :	fclean all
	@echo "full clean done"

.PHONY: re fclean all clean bonus
