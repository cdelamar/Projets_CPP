#include <iostream>
#include <iomanip>
#include <string>

class WashingMachine {
private:
    bool is_door_locked; // Variable privée, modifiable uniquement sous conditions
    bool is_running;     // Variable privée pour protéger l'état interne

    // Méthode privée pour verrouiller la porte
    void lockDoor() {
        is_door_locked = true;
    }

    // Méthode privée pour déverrouiller la porte
    void unlockDoor() {
        is_door_locked = false;
    }

public:
    WashingMachine() : is_door_locked(false), is_running(false) {}
    // Méthode publique pour démarrer le lavage
    void start() {
        if (!is_door_locked) {
            lockDoor(); // Verrouille la porte avant de démarrer
            is_running = true;
            std::cout << "Washing started.\n";
        } else {
            std::cout << "Door is already locked.\n";
        }
    }

    // Méthode publique pour arrêter le lavage
    void stop() {
        if (is_running) {
            is_running = false;
            unlockDoor(); // Déverrouille la porte après l'arrêt
            std::cout << "Washing stopped.\n";
        } else {
            std::cout << "The machine is not running.\n";
        }
    }

    // Méthode publique pour vérifier l'état de la porte
    bool isDoorLocked() const {
        return is_door_locked;
    }
};

int main() {
    WashingMachine wm;

    wm.start(); // Utilise l'interface publique
    std::cout << "Door locked: " << (wm.isDoorLocked() ? "Yes" : "No") << "\n";

    wm.stop(); // Arrête via l'interface publique
    std::cout << "Door locked: " << (wm.isDoorLocked() ? "Yes" : "No") << "\n";

    // wm.lockDoor(); // ERREUR : lockDoor est privée
    // wm.is_door_locked = false; // ERREUR : is_door_locked est privée

    return 0;
}