### VAR #######################################################
NAME		:=	philo

DEBUGGING	?=

LIBS		:=

HEADER		:=	-I includes

HEADERS		:=	includes/philo.h
OBJ_DIR		:=	./obj
SRC_DIR 	:=	./src

### UTILS #####################################################
# CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

SRC 	:=	main.c						\
			actions.c					\
			change.c					\
			check.c						\
			error_input.c				\
			fill.c						\
			init.c						\
			logic.c						\
			philo.c						\
			time.c						\
			utils/ft_is_number.c		\
			utils/frees.c 				\
			utils/ft_atoi_overflow.c	\
			utils/ft_atoll.c			\
			utils/ft_strlen.c			\
			utils/ft_isdigit.c			\
			utils/ft_putstr_fd.c		\

OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))
## BON_SRC :=

## BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)

## Regular Colors ##############################################
Color_Off	=	"\033[0m"			# Text Reset
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

### EXEC #######################################################

##DEBUGGING += -fsanitize=address -g
ifdef DEBUG
	DEBUGGING += -fsanitize=thread -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(Yellow) Building.. 🏠$(Color_Off)
	@echo -----------------------
	@$(CC) $^ -lpthread $(LIBS) $(DEBUGGING) -o $(NAME)
	@echo $(Green) Complete ✅ $(Color_Off)
	@echo -----------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo $(Purple) Compiling.. 🧱 $< $(Color_Off)
	@echo -----------------------
	@$(CC) $(DEBUGGING) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

clean:
	@echo $(Cyan) Sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(RM) $(OBJ)

fclean:
	@echo $(Red) Thorough sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(RM) $(NAME) $(OBJ)

re: fclean all

mem:
	memdetect $(SRC) $(LIBS) $(HEADER)

.PHONY: clean all fclean re
