# Nom de l'exécutable
NAME = zombie_horde

# Fichiers sources
SRC = main.cpp Zombie.cpp zombieHorde.cpp

# Fichiers objets (générés automatiquement à partir des sources)
OBJ = $(SRC:.cpp=.o)

# Options de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

# Règle par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compilation des fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(NAME)

# Reconstruit tout à partir de zéro
re: fclean all

# Évite que des fichiers nommés comme des règles soient pris par erreur
.PHONY: all clean fclean re
