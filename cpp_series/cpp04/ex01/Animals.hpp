#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Brain
{
	private:
		std::string	*ideas;
	public:
		Brain();
		~Brain();
		Brain(Brain & ref);
		Brain & operator=(Brain const & other);
		std::string *getIdeas();
};

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		Animal(Animal & ref);
		Animal & operator=(Animal const & rhs);
		virtual std::string getType( void ) const;
		virtual void makeSound() const;
};

class Cat: public Animal
{
	private:
		std::string	type;
		Brain		*brain;

	public:
		Cat();
		~Cat();
		Cat(Cat & ref);
		Cat & operator=(Cat const & other);
		void makeSound() const;
		std::string getType(void) const;
		Brain *getBrain(void)const;
		void compareTo(Cat const & other_Cat)const;
};

class Dog: public Animal
{
	private:
		std::string type;
		Brain		*brain;

	public:
		Dog();
		~Dog();
		Dog(Dog & ref);
		Dog & operator =(Dog const & other);
		void makeSound() const;
		std::string getType(void)const;
		Brain *getBrain(void)const;
		void compareTo(Dog const & other_Dog)const;
};

#endif

