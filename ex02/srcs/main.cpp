
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* generate( void ) {
	int i = rand() % 3;
	switch (i) {
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		return (NULL);
	}
}

void identify( Base* p ) {
	if (p == NULL)
		std::cout << "Pointer is NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Pointer is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer is C" << std::endl;
}

void identify( Base& p ) {
	try {
		A& temp = dynamic_cast<A&>(p);
		std::cout << "Reference is of type A" << std::endl;
		return ((void)temp);
	}
	catch(std::exception& e) {}
	try {
		B& temp = dynamic_cast<B&>(p);
		std::cout << "Reference is of type B" << std::endl;
		return ((void)temp);
	}
	catch(std::exception& e) {}
	try {
		C& temp = dynamic_cast<C&>(p);
		std::cout << "Reference is of type C" << std::endl;
		return ((void)temp);
	}
	catch(std::exception& e) {
		std::cerr << "Unknown casting or reference error" << std::endl;
		return ;
	};
}

int main(void) {
	B* bee = new B();
	identify(*bee);
	delete bee;
}
