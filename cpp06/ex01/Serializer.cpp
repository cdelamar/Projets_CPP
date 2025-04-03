#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &src) { *this = src; }
Serializer &Serializer::operator=(const Serializer &src) {(void)src; return *this; }


uintptr_t Serializer::serialize(Data *ptr)
{
	if (!ptr)
	{
        std::cout << "Warning: trying to serialize NULL pointer.\n";
        return 0;
    }
	//prend data ptr
	// converti en uintptr_t
	uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}


Data* Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
	{
        std::cout << "Warning: trying to deserialize NULL address.\n";
        return NULL;
    }
	// prend 'raw'
	// return 'raw' en tant que 'Data *'
	return ( reinterpret_cast<Data*>(raw) );
}