#include "AForm.hpp"

AForm::AForm(): name("Unnamed"), isSigned(false), gradeSign(HIGHTEST), gradeExec(HIGHTEST) {}

AForm::AForm(std::string name, int gradeSign, int gradeExec): name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{

	if (this->gradeSign < HIGHTEST)
	    throw AForm::GradeTooHighException();
	else if (this->gradeSign > LOWEST)
	    throw AForm::GradeTooLowException();

	if (this->gradeExec < HIGHTEST)
	    throw AForm::GradeTooHighException();
	else if (this->gradeExec > LOWEST)
	    throw AForm::GradeTooLowException();

	this->isSigned = false;
}

AForm::AForm(const AForm &copy): name(copy.getName() + "_copy"), isSigned(copy.isSigned), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{
	*this = copy;
}

AForm::~AForm() {}

AForm	&AForm::operator =(const AForm &src)
{
	if (this != &src)
	{
		this->isSigned = src.getIsSigned();
	}
	return *this;
}

std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getIsSigned() const
{
	return this->isSigned;
}

int	AForm::getGradeSign() const
{
	return this->gradeSign;
}

int	AForm::getGradeExec() const
{
	return this->gradeExec;
}

void	AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->gradeSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
	std::cout << "Bureaucrat " << bur.getName() << " successfully signed " << this->name << std::endl;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->gradeExec)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->name << std::endl;
		this->beExecuted(executor);
	}
}

char const	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low!");
}

std::ostream	&operator <<(std::ostream &o, const AForm &bur)
{
	o << "Form name: " << bur.getName() <<  std::endl;
	o << "Signed: " << bur.getIsSigned() << std::endl;
	o << "Grade to sign: " << bur.getGradeSign() << std::endl;
	o << "Grade to execute: " << bur.getGradeExec() << std::endl;

	return o;
}
