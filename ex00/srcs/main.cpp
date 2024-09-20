#include <iostream>
#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "You must give an Argument to convert" << std::endl;
		return (0);
	}
	std::string literal = argv[1];
	ScalarConverter::convert(literal);
}

// int main(void) {
// 	std::string a = "'c'";
// 	std::string b = "999";
// 	std::string c = "25.01f";
// 	std::string d = "34.01";

// 	std::cout << "Testing with 'c'" << "\n";
// 	ScalarConverter::convert(a);
// 	std::cout << "_________________" << "\n";
// 	std::cout << "Testing with 999" << "\n";
// 	ScalarConverter::convert(b);
// 	std::cout << "_________________" << "\n";
// 	std::cout << "Testing with 25.01f" << "\n";
// 	ScalarConverter::convert(c);
// 	std::cout << "_________________" << "\n";
// 	std::cout << "Testing with 34.01" << "\n";
// 	ScalarConverter::convert(d);
// 	std::cout << "_________________" << "\n";
// }
