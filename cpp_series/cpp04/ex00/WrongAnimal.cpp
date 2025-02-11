#include "Animals.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal is constructed\n";
	this->type = "Wanimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destroyed\n";
}

WrongAnimal::WrongAnimal(WrongAnimal & ref)
{
	this->type = ref.type;
	std::cout << "Wrong Animal is constructed from a copy constructor\n";
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other)
{
	this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "- wrong animal sounds -\n";
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}

