#include "Animals.hpp"

int main(void)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;

    delete dog;
    delete cat;

    std::cout << std::endl;
    std::cout << std::endl;

    Dog dawg;
    Cat picka;

    Dog& medor_ref = dawg;
    Cat& fifi_ref = picka;

    medor_ref.makeSound();
    fifi_ref.makeSound();

    std::cout << std::endl << "creating copies" << std::endl;
    Dog dawg_copy(dawg);
    Cat picka_copy(picka);

    Dog& dawg_copy_ref = dawg_copy;
    Cat& picka_copy_ref = picka_copy;

    std::cout << std::endl << "comparing..." << std::endl;

    dawg.compareTo(dawg_copy_ref);
    picka.compareTo(picka_copy_ref);
    std::cout << std::endl;

    const Animal* animal_array[4];
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

