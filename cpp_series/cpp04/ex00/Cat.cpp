#include "Animals.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "A cat is constructed\n";
}

Cat::~Cat()
{
	std::cout << "Cat destroyed\n";
}

Cat::Cat(Cat & ref)
{
	this->type = ref.getType();
	std::cout << "A cat is constructed from copy constructor\n";
}

Cat & Cat::operator=(Cat const & other)
{
	this->type = other.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "mmeeeyyyywww\n";
}

std::string Cat::getType( void ) const
{
	return (this->type);
}

