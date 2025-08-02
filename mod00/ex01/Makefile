# Variables
NAME        = PhoneBook
SRC         = PhoneBook.cpp \
							main.cpp
OBJ         = $(SRC:.cpp=.o)
CC         = g++
CCFLAGS    = -Wall -Wextra -Werror -g -std=c++98

# Règles
all: $(NAME)

$(NAME): $(OBJ) Makefile PhoneBook.hpp
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
