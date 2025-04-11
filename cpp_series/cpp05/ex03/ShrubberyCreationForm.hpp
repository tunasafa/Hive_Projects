#pragma once

#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm const	&operator=(ShrubberyCreationForm const &copy);

		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form);
