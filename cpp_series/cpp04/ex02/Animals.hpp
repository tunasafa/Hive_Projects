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

class AbsAnimal
{
	protected:
		std::string	type;
	public:
		AbsAnimal();
		virtual ~AbsAnimal() = 0;
		AbsAnimal(const AbsAnimal & ref);
		AbsAnimal & operator=(AbsAnimal const & other);
		virtual std::string getType(void)const;
		virtual void makeSound() const = 0;
};

class Cat: public AbsAnimal
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

class Dog: public AbsAnimal
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

