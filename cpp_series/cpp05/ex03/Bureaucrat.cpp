#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unnamed"), grade(LOWEST) {}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < HIGHTEST)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.getName() + "_copy")
{
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->grade = src.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < HIGHTEST)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high! Hightest grade is 1.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low! Lowest grade is 150.");
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}


std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
