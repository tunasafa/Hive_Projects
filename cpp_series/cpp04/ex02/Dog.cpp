#include "Animals.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "A dog is constructed with its brain\n";
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog is destroyed, with its brain\n";
}

Dog::Dog(Dog & ref)
{
	std::cout << "Creating a copy of dog brain\n";
	this->brain = new Brain(*(ref.getBrain()));
	this->type = ref.getType();
	std::cout << "A dog is constructed from copy constructor, but has its own brain\n";
}

Dog & Dog::operator=(Dog const & other)
{
	if (this->brain)
		delete (this->brain);
	this->brain = new Brain;
	this->type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "wwoorrff\n";
}

std::string Dog::getType(void)const
{
	return (this->type);
}

Brain *Dog::getBrain(void)const
{
	return (this->brain);
}

void Dog::compareTo(Dog const & other_dog) const
{
	std::cout << std::endl;
	std::cout << "Comparing dogs\n";
	std::cout << "My brains memory address: " << static_cast<void*>(this->brain) << std::endl;
	std::cout << "Others memory address: " << static_cast<void*>(other_dog.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brains ideas \t\t | \t\t\t Other brains ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other_dog.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
}

