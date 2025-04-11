#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", SIGN, EXEC), target("null") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm::AForm(copy), target(copy.target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->target = copy.target;
	return (*this);
}

void	PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	(void)bureaucrat;
	std::cout << this->target << " has been pardoned " << std::endl;
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeSign() << ", exec grade: " << form.getGradeExec());
}

