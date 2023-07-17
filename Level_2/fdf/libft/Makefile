# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 10:45:43 by mbernede          #+#    #+#              #
#    Updated: 2022/12/19 11:36:07 by kyuuh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	:= 		ft_atoi.c ft_bzero.c ft_calloc.c  ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c  ft_strjoin.c  ft_strlcat.c  ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c  ft_strncmp.c ft_strnstr.c  ft_strrchr.c  \
				ft_strtrim.c  ft_substr.c ft_tolower.c ft_toupper.c \
				get_next_line.c get_next_line_utils.c

BONUS	:=		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
				ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

RM 		:= 		rm -f

NAME	:=		libft.a

CFLAGS	:=		-Wall -Werror -Wextra

CC		:= 		cc

OBJ_DIR	:=		./objs/

SRC_DIR	:=		./srcs/

OBJ 	:= 		$(addprefix ${OBJ_DIR},${SRCS:.c=.o})
		
AR 		:= 		ar	-rc

BONUSOBJ:=		$(addprefix ${OBJ_DIR},${BONUS:.c=.o})

${NAME}:	${OBJ}
	@${AR} ${NAME} ${OBJ}
# @echo "libft.a made"

all : ${NAME}

${OBJ_DIR}%.o:		${SRC_DIR}%.c
	@${CC} ${CFLAGS} -o $@ -c $^

clean: 
	@${RM} ${OBJ} ${BONUSOBJ}
# @echo "libft cleaned"

fclean: 	clean
	@${RM} ${NAME}
# @echo "libft.a cleaned"

re: 	fclean all

bonus: ${OBJ} ${BONUSOBJ}
	@${AR} ${NAME} ${OBJ} ${BONUSOBJ}
# @echo "libft.a made with bonus"

.PHONY:		all clean fclean re bonus
