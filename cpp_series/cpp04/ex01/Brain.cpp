#include "Animals.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "AAAAAAAAAAA";
	std::cout << "A brain is constructed  with ideas\n";
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "Brain is destroyed\n";
}

Brain::Brain(Brain & ref)
{
	std::string *ref_ideas = ref.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref_ideas[i] + " stolen";
	std::cout << "A brain is constructed from copy constructor and stole others ideas\n";
}

Brain & Brain::operator=(Brain const & other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}

