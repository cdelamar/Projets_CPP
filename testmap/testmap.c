#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_border(char **map, int rows) {
    int max_len = 0;

    // Calcul de la longueur maximale d'une ligne
    for (int i = 0; i < rows; i++) {
        int len = strlen(map[i]);
        if (len > max_len) {
            max_len = len;
        }
    }

    // Vérification de la première ligne
    for (int j = 0; j < max_len; j++) {
        if (map[0][j] != '1' && map[0][j] != '\0')
            return false;
    }

    // Vérification de la dernière ligne
    for (int j = 0; j < max_len; j++) {
        if (map[rows-1][j] != '1' && map[rows-1][j] != '\0')
            return false;
    }

    // Vérification des bords latéraux
    for (int i = 0; i < rows; i++) {
        if (map[i][0] != '1')
            return false;

        int len = strlen(map[i]);
        if (len > 0 && map[i][len-1] != '1')
            return false;
    }

    return true;
}

int main() {
    char *map[] = {
        "111111",
        "100001",
        "101000001",
        "11000000000000101",
        "111111"
    };

    int rows = sizeof(map) / sizeof(map[0]);
    if (is_valid_border(map, rows)) {
        printf("La map est valide !\n");
    } else {
        printf("La map n'est pas valide !\n");
    }
    return 0;
}
