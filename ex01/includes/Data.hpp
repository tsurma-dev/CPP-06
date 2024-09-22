#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>

class Data
{
private:
public:
	Data( std::string str );
	Data( Data& other );
	Data& operator=( Data& other );
	~Data();
	std::string _str;
};



#endif