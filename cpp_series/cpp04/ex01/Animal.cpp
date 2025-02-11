#include "Animals.hpp"

Animal::Animal()
{
	std::cout << "An animal is constructed\n";
	this->type = "animal";
}

Animal::~Animal()
{
	std::cout << "Animal destroyed\n";
}

Animal::Animal(Animal & ref)
{
	this->type = ref.type;
	std::cout << "Animal from a copy constructor\n";
}

Animal & Animal::operator=(Animal const & other)
{
	this->type = other.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "- general animal sound -\n";
}

std::string Animal::getType( void ) const
{
	return (this->type);
}

