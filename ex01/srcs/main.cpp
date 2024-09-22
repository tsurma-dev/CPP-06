
#include "../includes/Serializer.hpp"

int main(void) {
	Data data("Hello");
	uintptr_t store;

	store = Serializer::serialize(&data);

	std::cout << &data << "\n" << store << "\n" << Serializer::deserialize(store) << std::endl;
}