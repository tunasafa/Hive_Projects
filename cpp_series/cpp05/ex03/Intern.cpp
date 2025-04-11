#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void) {}

Intern const	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

static AForm	*createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm				*createdForm = NULL;
	const std::string	formsNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*formsFun[])(std::string target) = {&createShrubbery, &createRobotomy, &createPresident};
	size_t	size = sizeof(formsNames) / sizeof(formsNames[0]);

	for (size_t cur = 0; cur < size; cur++)
	{
		if (name == formsNames[cur])
		{
			createdForm = formsFun[cur](target);
			break ;
		}
	}
	if (!createdForm)
		std::cout << "Form with the name \"" << name << "\" doesn't exists, but I can create the following forms : \"shrubbery creation\", \"robotomy creation\", \"presidential pardon\"." << std::endl; 
	
	return createdForm ;
}


