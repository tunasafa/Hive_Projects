#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Target constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm target constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Execute method
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // Check if the form can be executed
    this->checkExecutionRequirements(executor);
    
    // Make drilling noises
    std::cout << "* DRILLING NOISES * Bzzzzz... Vrrrrrr... Drrrrrr..." << std::endl;
    
    // Seed the random number generator
    std::srand(std::time(0));
    
    // 50% chance of success
    if (std::rand() % 2) {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->target << " failed." << std::endl;
    }
}

// Getter
const std::string& RobotomyRequestForm::getTarget() const {
    return this->target;
}
