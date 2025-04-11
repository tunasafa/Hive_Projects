#include "AForm.hpp"

// Default constructor
AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

// Assignment operator
AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        // Cannot assign to const attributes, so we only assign isSigned
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

// Getters
const std::string& AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

// Form signing
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

// Check execution requirements
void AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
    if (!this->isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
}

// Exception methods
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high! It should be between 1 and 150.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low! It should be between 1 and 150.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed yet!";
}

// Insertion operator
std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form: " << form.getName() 
        << ", sign grade: " << form.getGradeToSign() 
        << ", execute grade: " << form.getGradeToExecute()
        << ", signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}
