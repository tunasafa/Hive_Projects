#include "Animals.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "A cat was constructed, with its new brain\n";
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat is destroyed, and its brain deleted\n";
}

Cat::Cat(Cat & ref)
{
	this->type = ref.getType();
	this->brain = new Brain(*(ref.getBrain()));
	std::cout << "A cat was constructed from copy constructor, but has its own brain\n";
}

Cat & Cat::operator=(Cat const & other)
{
	this->type = other.type;
	if (this->brain)
		delete (this->brain);
	this->brain = new Brain(*(other.getBrain()));
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meeeyyyww\n";
}

std::string Cat::getType( void ) const
{
	return (this->type);
}

Brain *Cat::getBrain( void ) const
{
	return (this->brain);
}

void Cat::compareTo(Cat const & other_cat) const
{
	std::cout << std::endl;
	std::cout << "Comparing two cats\n";
	std::cout << "My brain's memory address: " << static_cast<void*>(this->brain) << std::endl;
	std::cout << "Others memory address: " << static_cast<void*>(other_cat.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brains ideas \t\t | \t\t\t Other brains ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_cat.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}

