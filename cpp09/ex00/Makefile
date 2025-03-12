NAME = ex00

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Weffc++

HARDCOREFLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow -Wold-style-cast -Woverloaded-virtual \
                -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 \
                -Wlogical-op -O2 -march=native -mtune=native -fstrict-aliasing -flto -g3 \
                -fno-omit-frame-pointer -DDEBUG

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
