NAME = ex01

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Weffc++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
