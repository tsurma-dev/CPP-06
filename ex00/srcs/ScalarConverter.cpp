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

static bool isChar( std::string& literal ) {
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (true);
	return (false);
}

static bool isInt( std::string& literal ) {
	char *endptr;
	long numberStore = strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0' && numberStore >= std::numeric_limits<int>::min() && numberStore <= std::numeric_limits<int>::max())
		return (true);
	return (false);
}

static bool isFloat( std::string& literal ) {
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return (false);
	char* end;
	strtod(literal.c_str(), &end);
	return *end == 'f' && end == &literal[literal.length() - 1];
}

static bool isDouble( std::string& literal ) {
	char *endptr;
	strtod(literal.c_str(), &endptr);
	if (*endptr == '\0')
		return (true);
	return (false);
}

static bool isPseudoLiteral( std::string& literal ) {
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (true);
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (true);
	return (false);
}

static void convertFromPseudoLiteral( std::string& literal ) {
	if (literal == "nan" || literal == "nanf")
		std::cout << "char:\tImpossible\nint:\tImpossible\nfloat:\tnanf\ndouble:\tnan" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "char:\tImpossible\nint:\tImpossible\nfloat:\t+inff\ndouble:\t+inf" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "char:\tImpossible\nint:\tImpossible\nfloat:\t-inff\ndouble:\t-inf" << std::endl;
}

static void convertFromChar ( char c ) {
	if (isprint(c))
		std::cout << "char:\t'" << c << "'\n";
	else
		std::cout << "char:\tNon displayable\n";
	std::cout << "int:\t" << static_cast<int>(c) << "\n";
	std::cout.precision(0);
	std::cout << std::fixed << "float:\t" << static_cast<float>(c) << ".0f\n";
	std::cout << std::fixed << "double:\t" << static_cast<double>(c) << ".0" << std::endl;
}

static void convertFromInt( int i ) {
	if (i > 127 || i < 0)
		std::cout << "char:\tImpossible\n";
	else if (isprint(static_cast<char>(i)))
		std::cout << "char:\t'" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char:\tNon displayable\n";
	std::cout.precision(0);
	std::cout << "int:\t" << i << "\n";
	std::cout << std::fixed << "float:\t" << static_cast<float>(i) << ".0f\n";
	std::cout << std::fixed << "double:\t" << static_cast<double>(i) << ".0" << std::endl;
}

static void convertFromFloat( float f ) {
	if (f > 127 || f < 0)
		std::cout << "char:\tImpossible\n";
	else if (isprint(static_cast<char>(f)))
		std::cout << "char:\t'" << static_cast<char>(f) << "'\n";
	else
		std::cout << "char:\tNon displayable\n";
	std::cout.precision(1);
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int:\t" << static_cast<int>(f) << "\n";
		else
	std::cout << "int:\timpossible\n";
	std::cout << std::fixed << "float:\t" << f << "f\n";
	std::cout << std::fixed << "double:\t" << static_cast<double>(f) << std::endl;
}

static void convertFromDouble( double d ) {
	if (d > 127 || d < 0)
		std::cout << "char:\tImpossible\n";
	else if (isprint(static_cast<char>(d)))
		std::cout << "char:\t'" << static_cast<char>(d) << "'\n";
	else
		std::cout << "char:\tNon displayable\n";
	std::cout.precision(1);
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int:\t" << static_cast<int>(d) << "\n";
	else
		std::cout << "int:\timpossible\n";
	if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
		std::cout << std::fixed << "float:\t" << static_cast<float>(d) << "f\n";
	else
		std::cout  << "float:\timpossible\n";
	std::cout << std::fixed << "double:\t" << d << std::endl;
}

void ScalarConverter::convert( std::string& literal ) {
	if (isPseudoLiteral(literal))
		convertFromPseudoLiteral(literal);
	else if (isChar(literal))
		convertFromChar(literal[1]);
	else if (isInt(literal))
		convertFromInt(atoi(literal.c_str()));
	else if (isFloat(literal))
		convertFromFloat(atof(literal.c_str()));
	else if (isDouble(literal))
		convertFromDouble(strtod(literal.c_str(), NULL));
	else
		std::cerr << "Conversion from literal impossible" << std::endl;
}
