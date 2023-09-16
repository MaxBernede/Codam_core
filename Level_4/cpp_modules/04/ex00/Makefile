NAME := exe
CXX := c++
CXXFLAGS := -Wall -Wextra -std=c++98 -fsanitize=address -g -Wshadow
RM := rm -rf

SRC :=	main.cpp	\
		Dog.cpp		\
		Cat.cpp		\
		Animal.cpp	\

INC:=	Animal.hpp\
		Dog.hpp\
		Cat.hpp\

OBJ_DIR :=	./obj
OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(INC) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: clean all fclean re run

