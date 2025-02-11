#include "Animals.hpp"

WrongCat::WrongCat()
{
	this->type = "Wcat";
	std::cout << "A wrong cat is constructed\n";
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong cat destroyed\n";
}

WrongCat::WrongCat(WrongCat & ref)
{
	this->type = ref.getType();
	std::cout << "A cat is constructed from copy constructor\n";
}

WrongCat & WrongCat::operator=(WrongCat const & other)
{
	this->type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong meeyyww\n";
}

