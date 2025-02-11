#include "Animals.hpp"

AbsAnimal::AbsAnimal()
{
	this->type = "Abstract Animal";
	std::cout << "Abstract animal constructed\n";
}

AbsAnimal::~AbsAnimal()
{
	std::cout << "Abstract animal destroyed\n";
}

AbsAnimal::AbsAnimal(AbsAnimal const & ref)
{
	this->type = ref.getType();
	std::cout << "Abstract animal is constructed from a copy\n";
}

AbsAnimal & AbsAnimal::operator=(AbsAnimal const & other)
{
	this->type = other.getType();
	return (*this);
}

void AbsAnimal::makeSound() const
{
	std::cout << "- general animal sound -\n";
}

std::string AbsAnimal::getType(void)const
{
	return (this->type);
}

