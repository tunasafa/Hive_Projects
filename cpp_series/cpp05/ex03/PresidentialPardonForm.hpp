#pragma once

#include "AForm.hpp"

#define SIGN 25
#define EXEC 5

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &copy);

		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);
