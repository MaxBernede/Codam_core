
NAME		:=	megaphone

DEBUGGING	?=

LIBS		:=

HEADER		:=	-Iincludes

HEADERS		:=
OBJ_DIR		:=	./obj
SRC_DIR		:=	./src

#-Werror
CXXFLAGS	:=	-Wall -Wextra -std=c++98
RM			:=	rm -rf

SRC			:=	megaphone.cpp

OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC			:=	$(addprefix $(SRC_DIR)/,$(SRC))

ifdef DEBUG
	DEBUGGING += -fsanitize=address -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building.. 🏠"
	@echo "-----------------------"
	@$(CXX) $^ -lpthread $(LIBS) $(DEBUGGING) -o $(NAME)
	@echo "Complete ✅"
	@echo "-----------------------"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "Compiling.. 🧱 $<"
	@echo "-----------------------"
	@c++ $(DEBUGGING) $(CXXFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

clean:
	@echo "Sweeping.. 💥"
	@echo "-----------------------"
	@$(RM) $(OBJ)

fclean:
	@echo "Thorough sweeping.. 💥"
	@echo "-----------------------"
	@$(RM) $(NAME) $(OBJ)

re:	fclean all

.PHONY: clean all fclean re
