NAME := exe
CXX := c++
<<<<<<< HEAD
CXXFLAGS := -Wall -Wextra -Werror -std=c++11 -fsanitize=address -g
RM := rm -rf

SRC := $(wildcard *.cpp)

INC:=	$(wildcard *.hpp)
=======
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
RM := rm -rf

SRC :=	main.cpp		\
		Bureaucrat.cpp	\

INC:=	Bureaucrat.hpp	\
>>>>>>> 7b9f7abdb1ff73840d29d8dd7f566e3bc7078d45

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

