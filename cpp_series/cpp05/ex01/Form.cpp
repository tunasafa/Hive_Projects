// Form.cpp
#include "Form.hpp"

// Default constructor
Form::Form() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "Form parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

// Assignment operator
Form& Form::operator=(const Form& other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other) {
        // Cannot assign to const attributes, so we only assign isSigned
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

// Getters
const std::string& Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

// Form signing
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

// Exception methods
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! It should be between 1 and 150.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! It should be between 1 and 150.";
}

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() 
        << ", sign grade: " << form.getGradeToSign() 
        << ", execute grade: " << form.getGradeToExecute()
        << ", signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}
