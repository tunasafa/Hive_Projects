#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Target constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Execute method
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // Check if the form can be executed
    this->checkExecutionRequirements(executor);
    
    std::string filename = this->target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile) {
        throw std::runtime_error("Could not create file: " + filename);
    }
    
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
    std::cout << "Created file: " << filename << " with ASCII trees" << std::endl;
}

// Getter
const std::string& ShrubberyCreationForm::getTarget() const {
    return this->target;
}
