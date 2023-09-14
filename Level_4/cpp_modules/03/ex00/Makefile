NAME := exe
CXX := c++
CXXFLAGS := -Wall -Wextra -std=c++98 -fsanitize=address -g
RM := rm -rf
SRC :=	main.cpp	\
		ClapTrap.cpp\

OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

%.o: %.cpp ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re
