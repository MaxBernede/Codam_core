
NAME		:=	megaphone

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
RM			:=	rm -rf

SRC			:=	megaphone.cpp

OBJ			:=	$(SRC:.cpp=.o)
SRC			:=	$(SRC)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CXXFLAGS) $^ -o $(NAME)

%.o: %.cpp
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Sweeping.. 💥"
	@$(RM) $(OBJ)

fclean:
	@echo "Thorough sweeping.. 💥"
	@$(RM) $(NAME) $(OBJ)

re:	fclean all

.PHONY: clean all fclean re
