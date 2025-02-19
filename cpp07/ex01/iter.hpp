#pragma once

// ex01 : iter

// on cree une 'fonction generique' (function template)
// iter prend 3 params
// 1. adresse de tableau :

// 2. taille de tableau (simple)

// 3. une fonction qu'on exec sur chaque element de tableaux


// >> quel interet ?
// En C++, on peut se resservir d'une fonction generique sur different type de data
// exemple : revoir l'ex00 avec min et max,
// capable de prendre en argument le nom d'un personnage aussi bien que son level
// Plus besoin de refaire la meme fonction pour retourner un autre type de donnee, top

// >> comment ca marche ?
// c'est pas tres complique :
// - quand on declare une fonction avec 'template <typename Truc>',
// on informe le compilateur qu'il va devoir s'adapter sur le type de data, magique
// - comme pour les operateur de surcharge, c'est du 'syntactic sugar';
// meme si le C++ est pas toujours evident a lire, les templates sont la pour le confort du dev
// - plus pragmatiquement, c'est aussi plus secure qu'un cast sur du (*void)

// >> pourquoi pas juste cast sur un void, a l'ancienne ?
// pas peu fier de cette question :
// - en C ca peu le faire mais en C++ c'est loin d'etre safe
// - De toute facon, tous les type de data peuvent pas etre cast depuis un void
// 'template' est specialement concu pour que le compilateur comprenne qu'on sait pas encore sur quoi on va bosser

// >> dis donc c'est vachement bien, mais du coup pourquoi pas faire toutes ces fonctions en templates si c'est si bien ?
// faut pas abuser non plus :
// - les templates, c'est pas ce qui ya de plus lisible
// - c'est pas le plus opti non plus a la compilation
// - en plus c'est chiant a ecire


template <typename T>
void iter() {

}




//exemple perso pour le kiff
/*
template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b) ? a : b;
}

class Character {
private:
    std::string name;
    int hp; // Points de vie

public:
    Character(std::string n, int h) : name(n), hp(h) {}

    bool operator>(Character const &other) const {
        return this->hp > other.hp;
    }

    void display() const {
        std::cout << name << " (HP: " << hp << ")" << std::endl;
    }
};

int main() {
    Character warrior("Guerrier", 35);
    Character wizard("Magicien", 19);

    std::cout << "Le plus fort des deux est : ";
    max(warrior, wizard).display();

    return 0;
}
*/