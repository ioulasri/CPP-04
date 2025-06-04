#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << "Animal assignment operator called" << std::endl;
	}
	return *this;
}

void Animal::makeSound() const {
	;
}

std::string Animal::getType() const {
	return type;
}

std::ostream &operator<<(std::ostream &os, const Animal &animal) {
	os << "Animal type: " << animal.getType();
	return os;
}

