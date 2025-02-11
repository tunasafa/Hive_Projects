#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

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

	public:
		Cat();
		~Cat();
		Cat(Cat & ref);
		Cat & operator=(Cat const & other);
		void makeSound() const;
		std::string getType( void ) const;
};

class Dog: public Animal
{
	private:
		std::string type;

	public:
		Dog();
		~Dog();
		Dog(Dog & ref);
		Dog & operator =(Dog const & other);
		void makeSound() const;
		std::string getType( void ) const;
};

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal & ref);
		WrongAnimal & operator=(WrongAnimal const & other);
		void makeSound() const;
		std::string getType( void ) const;
};

class WrongCat: public WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat & ref);
		WrongCat & operator=(WrongCat const & other);
		void makeSound() const;
};

#endif

