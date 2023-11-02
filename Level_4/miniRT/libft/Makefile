NAME	:= libft.a
HEADER	:= libft.h
OBJ_DIR	:= ./obj
CC		:= gcc
CFLAGS	:=	-Wall -Wextra -Werror
#LDFLAGS ?= 
RM		:=	rm -f

SRC 	:=	ft_atoi.c 		\
			ft_bzero.c 		\
			ft_isalpha.c 	\
			ft_isalnum.c 	\
			ft_isascii.c 	\
			ft_isdigit.c 	\
			ft_isprint.c 	\
			ft_isspace.c	\
			ft_memchr.c 	\
			ft_memcmp.c 	\
			ft_memcpy.c 	\
			ft_memmove.c 	\
			ft_memset.c 	\
			ft_strchr.c 	\
			ft_strlcat.c 	\
			ft_strlcpy.c 	\
			ft_strlen.c 	\
			ft_strncmp.c 	\
			ft_strnstr.c 	\
			ft_strrchr.c 	\
			ft_tolower.c 	\
			ft_toupper.c 	\
			ft_calloc.c 	\
			ft_strdup.c 	\
			ft_substr.c 	\
			ft_strjoin.c 	\
			ft_strtrim.c 	\
			ft_itoa.c 		\
			ft_strmapi.c 	\
			ft_striteri.c 	\
			ft_putchar_fd.c \
			ft_putstr_fd.c 	\
			ft_putendl_fd.c \
			ft_putnbr_fd.c 	\
			ft_split.c 		\
			ft_atoh.c		\
			ft_atol.c		\
			ft_atoi_overflow.c 				\
			ft_2d_arrlen.c					\
			ft_2dfree.c						\
			ft_strjoin_free.c				\
			ft_2d_add.c						\
			ft_basetoa.c					\
			ft_string_injection.c			\
			\
			ft_printf/src/put_basetoa.c		\
			ft_printf/src/ft_printf.c		\
			ft_printf/src/functions.c		\
			ft_printf/src/hexfunctions.c	\
			ft_printf/src/printf_utils.c	\
			\
			get_next_line/get_next_line.c		\
			get_next_line/get_next_line_utils.c	\

BON_SRC :=	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c



OBJ		:=	$(SRC:.c=.o)
BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)


all: $(NAME)

bonus: $(OBJ) $(BON_OBJ)
	@ar -rc $(NAME) $^

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^

clean:
	@$(RM) $(OBJ) $(BON_OBJ)

fclean: 
	@$(RM) $(NAME) $(OBJ) $(BON_OBJ)

re: fclean all

.PHONY: clean all fclean re Bonus