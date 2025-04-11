#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat boss("CEO", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat employee("Employee", 100);

        std::cout << "\nCreated bureaucrats:" << std::endl;
        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << employee << std::endl;

        // Create forms
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Coworker");
        PresidentialPardonForm pardon("Criminal");

        std::cout << "\nCreated forms:" << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Test signing forms
        std::cout << "\n--- Testing signing forms ---" << std::endl;
        employee.signForm(shrubbery);
        manager.signForm(robotomy);
        boss.signForm(pardon);

        // Test executing forms
        std::cout << "\n--- Testing executing forms ---" << std::endl;

        try {
            ShrubberyCreationForm unsignedShrubbery("UnsignedTest");
            employee.executeForm(unsignedShrubbery);  // should fail - not signed
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            employee.executeForm(shrubbery);  // should work (grade 100 < 137)
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            manager.executeForm(robotomy);  // should work (grade 40 < 45)
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            boss.executeForm(pardon);  // should work (grade 1 < 5)
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            Bureaucrat almostManager("Assistant Manager", 46);
            almostManager.executeForm(robotomy);  // should fail (grade 46 > 45)
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}

