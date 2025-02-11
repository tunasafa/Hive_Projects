#include "Animals.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "A dog is constructed\n";
}

Dog::~Dog()
{
	std::cout << "Dog destroyed\n";
}

Dog::Dog(Dog & ref)
{
	this->type = ref.getType();
	std::cout << "A dog is constructed from copy constructor\n";
}

Dog & Dog::operator=(Dog const & other)
{
	this->type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woorrf\n";
}

std::string Dog::getType( void ) const
{
	return (this->type);
}

