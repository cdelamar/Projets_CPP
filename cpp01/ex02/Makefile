# Nom de l'exécutable
NAME = brain_program

# Fichiers sources
SRC = main.cpp

# Fichiers objets générés
OBJ = $(SRC:.cpp=.o)

# Options de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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

# Recompilation complète
re: fclean all

# Évite les erreurs si ces noms existent en tant que fichiers
.PHONY: all clean fclean re
