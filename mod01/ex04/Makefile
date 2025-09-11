# Variables
NAME        = sed
SRC         = main.cpp
OBJ         = $(SRC:.cpp=.o)
CC         = g++
CCFLAGS    = -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
