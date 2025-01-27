// Harl.cpp
#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "DEBUG: I love having extra bacon for my burger." << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO: Adding extra bacon costs more? Unbelievable!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING: I deserve free bacon. I am a loyal customer." << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR: This is unacceptable! Call the manager now!" << std::endl;
}

void Harl::complain(std::string level) { // pour eviter les if else

    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error };

    std::string level_tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level_tab[i] == level) {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Unknown complaint level!" << std::endl;
}
