#include "Serializer.hpp"

int main() {
    Data original;
    original.value = 42;
    original.dataAdress = "Hello serialization";

    uintptr_t raw = Serializer::serialize(&original);

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original address : " << &original << std::endl;
    std::cout << "Recovered address: " << recovered << std::endl;

    std::cout << "Recovered value  : " << recovered->value << std::endl;
    std::cout << "Recovered string : " << recovered->dataAdress << std::endl;

    return 0;
}
