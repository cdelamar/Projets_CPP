#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &src) { *this = src; }
Serializer &Serializer::operator=(const Serializer &src) {(void)src; return *this; }


uintptr_t Serializer::serialize(Data *ptr)
{
	//prend data ptr
	// converti en uintptr_t
	uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}


Data* Serializer::deserialize(uintptr_t raw)
{
	// prend 'raw'
	// return 'raw' en tant que 'Data *'
	Data *data = reinterpret_cast<Data*>(raw);

}