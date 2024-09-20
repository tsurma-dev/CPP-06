#ifndef SCALAR_CONVERTER_HPP_
#define SCALAR_CONVERTER_HPP_

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
//	Orthodox canonical Form
	ScalarConverter();
	ScalarConverter( ScalarConverter& other);
	ScalarConverter& operator=( ScalarConverter& other);
	~ScalarConverter();
public:
//	convert
	static void convert( std::string& );
};

#endif
