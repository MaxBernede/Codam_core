# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 12:30:59 by mbernede          #+#    #+#              #
#    Updated: 2022/10/19 17:58:51 by mbernede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	:= 		ft_printf.c ft_itoahuge.c

RM 		:= 		rm -f

NAME	:=		libftprintf.a

CFLAGS	:=		-Wall -Werror -Wextra

CC		:= 		cc

OBJ 	:= 		${SRCS:.c=.o}

AR 		:= 		ar	-rs

${NAME}:	${OBJ}
	make -C ./libft
	cp ./libft/libft.a ./libftprintf.a
	${AR} ${NAME} ${OBJ}

all : ${NAME}

%.o:		%.c
	${CC} ${CFLAGS} -c $^

clean: 
	${RM} ${OBJ} && make clean -C ./libft

fclean: 	clean
	${RM} ${NAME} && make fclean -C ./libft

re: 	fclean all

.PHONY:		all clean fclean re 
