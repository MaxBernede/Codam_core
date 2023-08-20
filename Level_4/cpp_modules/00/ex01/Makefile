NAME := phonebook
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf
SRC := main.cpp Contact.cpp Phonebook.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

%.o: %.cpp Contact.hpp Phonebook.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re
