#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    std::cout << "Parameterized constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        // Cannot assign to const name, so we don't
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

// Grade manipulation
void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

// Form signing
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->name << " couldn't sign " << form.getName() 
                 << " because " << e.what() << std::endl;
    }
}

// Form execution
void Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->name << " couldn't execute " << form.getName() 
                 << " because " << e.what() << std::endl;
    }
}

// Exception methods
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! It should be between 1 and 150.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! It should be between 1 and 150.";
}

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
