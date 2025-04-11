#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", 25, 5), target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Target constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm target constructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), target(other.target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Execute method
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    // Check if the form can be executed
    this->checkExecutionRequirements(executor);
    
    // Inform about the pardon
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Getter
const std::string& PresidentialPardonForm::getTarget() const {
    return this->target;
}
