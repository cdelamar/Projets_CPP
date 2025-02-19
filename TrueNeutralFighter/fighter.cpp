#include <iostream>
#include <string>

class Adventurer {
private:
    std::string name;
    std::string race;
    std::string Adventurer_class;
    std::string alignment;
    int strength;
    int intelligence;
    int dexterity;
    int constitution;
    int wisdom;
    int charisma;

public:
    // Constructor
    Adventurer(std::string n, std::string r, std::string c, std::string a,
              int str, int intl, int dex, int con, int wis, int cha)
        : name(n), race(r), Adventurer_class(c), alignment(a),
          strength(str), intelligence(intl), dexterity(dex),
          constitution(con), wisdom(wis), charisma(cha) {}

    // Display Adventurer stats
    void display_stats() {
        std::cout << "Name: " << name << "\n"
                  << "Race: " << race << "\n"
                  << "Class: " << Adventurer_class << "\n"
                  << "Alignment: " << alignment << "\n"
                  << "Strength: " << strength << "\n"
                  << "Intelligence: " << intelligence << "\n"
                  << "Dexterity: " << dexterity << "\n"
                  << "Constitution: " << constitution << "\n"
                  << "Wisdom: " << wisdom << "\n"
                  << "Charisma: " << charisma << "\n";
    }
};

int main() {
    // Example Adventurer creation
    Adventurer my_Adventurer("Aragorn", "Human", "Fighter", "True Neutral",
                           18, 14, 16, 15, 12, 10);
    my_Adventurer.display_stats();
    return 0;
}
