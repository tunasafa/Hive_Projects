#include "Animals.hpp"

int main( void )
{
	const AbsAnimal* dog = new Dog();
	const AbsAnimal* cat = new Cat();

	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << std::endl;


	Dog doggo;
	Cat katto;

	Dog & doggo_ref = doggo;
	Cat & katto_ref = katto;

	std::cout << std::endl << "creating copies" << std::endl;
	Dog doggo_copy(doggo_ref);
	Cat katto_copy(katto_ref);

	Dog & doggo_copy_ref = doggo_copy;
	Cat & katto_copy_ref = katto_copy;

	std::cout << std::endl << "comparing..." << std::endl;
	doggo.compareTo(doggo_copy_ref);
	katto.compareTo(katto_copy_ref);
	std::cout << std::endl;



	const AbsAnimal	*(animal_array[4]);
	std::cout << std::endl;

	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;


	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;

}

