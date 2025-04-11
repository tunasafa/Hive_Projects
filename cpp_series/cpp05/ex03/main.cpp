#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try 
    {
        // Create an intern
        Intern someRandomIntern;

        // Create a bureaucrat with a high enough grade
        Bureaucrat highLevelBureaucrat("Mike", 1);

        // Test valid form creation by the intern
        std::cout << "\nCreating valid forms using the intern:\n\n";

        // Intern creates a ShrubberyCreationForm
        AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (shrubberyForm) 
        {
            highLevelBureaucrat.signForm(*shrubberyForm);
            highLevelBureaucrat.executeForm(*shrubberyForm);
            delete shrubberyForm;  // Don't forget to clean up!
        }
        else
        {
            std::cout << "The intern could not create the requested form!" << std::endl;
        }

        // Intern creates a RobotomyRequestForm
        AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "First");
        if (robotomyForm) 
        {
            highLevelBureaucrat.signForm(*robotomyForm);
            highLevelBureaucrat.executeForm(*robotomyForm);
            delete robotomyForm;
        }
        else
        {
            std::cout << "The intern could not create the requested form!" << std::endl;
        }

        // Intern creates a PresidentialPardonForm
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Dave");
        if (pardonForm) 
        {
            highLevelBureaucrat.signForm(*pardonForm);
            highLevelBureaucrat.executeForm(*pardonForm);
            delete pardonForm;
        }
        else
        {
            std::cout << "The intern could not create the requested form!" << std::endl;
        }

        std::cout << "\n---------------------------------------\n";

        // Test with an invalid form type
        std::cout << "\nTrying to create an invalid form:\n\n";
        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "some target");
        if (!invalidForm) 
        {
            std::cout << "The intern could not create the requested form!" << std::endl;
        }
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
