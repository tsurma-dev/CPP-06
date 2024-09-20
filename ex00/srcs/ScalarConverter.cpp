#include "../includes/ScalarConverter.hpp"


//Orthodox canocnical Form
ScalarConverter::ScalarConverter(){
	  std::cout << "\033[34mScalar Converter\t default constructor call.\033[0m" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter& other ) {
	*this = other;
	std::cout << "\033[34mScalar Converter\t copy constructor call.\033[0m" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
	std::cout << "\033[34mScalar Converter\t copy assignment call.\033[0m" << std::endl;
	if (this == &other) { return (*this); }
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "\033[34mScalar Converter\t destructor call.\033[0m" << std::endl;
}

//convert
void ScalarConverter::convert(std::string str) {
	if (str.length() == 0) {
		return ;
	}
	double numberStore;

	std::stringstream ss(str);
	ss >> numberStore;
	if (ss.fail()) {
		std::cout << "IMPOSSIBLE" << std::endl;
	}

	if (isprint(static_cast<char>(numberStore)))
		std::cout << "Char:\t" << static_cast<char>(numberStore) << "\n";
	else
		std::cout << "Char:\tImpossible" << "\n";

	if (numberStore > __INT32_MAX__ || numberStore < (-__INT32_MAX__) - 1)
		std::cout << "Int:\tImpossible\n";
	else
		std::cout << "Int:\t" << static_cast<int>(numberStore) << "\n";

	if (std::isnan(numberStore))
		std::cout << "Double:\tnan\n";
	else
		std::cout << "Double:\t" << numberStore << "\n";
}

// static void printAsChar() {

// }
