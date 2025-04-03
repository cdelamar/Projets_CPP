#include "Serializer.hpp"

int main() {
    Data original;
    original.value = 420;
    original.dataAdress = "test bonjour";

    uintptr_t raw = Serializer::serialize(&original);
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original address : " << &original << std::endl;

    if (recovered)
    {
        std::cout << "Recovered address: " << recovered << std::endl;
        std::cout << "Recovered value  : " << recovered->value << std::endl;
        std::cout << "Recovered string : " << recovered->dataAdress << std::endl;
        
        if (&original == recovered)
            std::cout << "Pointers match: ✔" << std::endl;
        else
            std::cout << "Pointers DO NOT match: ✘" << std::endl;
    }

    else
        std::cout << "Recovered pointer is NULL, cannot access members.\n";
    return 0;
}
