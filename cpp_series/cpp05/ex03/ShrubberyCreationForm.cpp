#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), target("null") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm(copy), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->target = copy.target;
	return (*this);
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const
{
    std::ofstream outfile;
    std::string filename = this->target + "_shrubbery";
    outfile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    try
    {
        outfile.open(filename.c_str());

        outfile << "        (~.~)" << std::endl;
        outfile << "    (~~.......~~)" << std::endl;
        outfile << " (~~.............~~)" << std::endl;
        outfile << "(....................)" << std::endl;
        outfile << " (...._-.....-_....)" << std::endl;
        outfile << "   (~.. \\\\ // ..~)" << std::endl;
        outfile << "        ||||| " << std::endl;
        outfile << "        ||||| " << std::endl;
        outfile << "       /// \\\\\\" << std::endl;

        outfile.close();
        std::cout << bureaucrat.getName() << " successfully created a shrubbery in " << filename << std::endl;
    }
    catch (const std::ofstream::failure &e)
    {
        std::cerr << "Error: Could not write to " << filename << std::endl;
    }
}


std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeSign() << ", exec grade: " << form.getGradeExec());
}

