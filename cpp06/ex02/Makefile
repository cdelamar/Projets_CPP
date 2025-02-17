NAME = Base_Random

SRC = main.cpp Base.cpp

OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Weffc++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

hardcore: clean
	$(CC) $(HARDCOREFLAGS) $(SRC) -o $(NAME)_hardcore

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)_hardcore

re: fclean all
