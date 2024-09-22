#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <iostream>
#include <stdint.h>
#include "Data.hpp"


class Serializer
{
private:
	// Orthodox canonical Form
	Serializer(/* args */);
	Serializer( Serializer& other );
	Serializer& operator=( Serializer& );
	~Serializer();
public:
	static uintptr_t serialize( Data* ptr );
	static Data* deserialize( uintptr_t raw );
};

#endif