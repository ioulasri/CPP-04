#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	virtual void makeSound() const;
	std::string getType() const;
};

std::ostream &operator<<(std::ostream &os, const Animal &animal);

#endif // ANIMAL_HPP