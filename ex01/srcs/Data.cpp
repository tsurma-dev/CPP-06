#include "../includes/Data.hpp"


Data::Data(std::string str) {
	this->_str = str;
}

Data::Data(Data& other) {
	*this = other;
}

Data &Data::operator=(Data& other) {
	if (this == &other) { return(*this);}
	this->_str = other._str;
	return (*this);
}

Data::~Data() {
}