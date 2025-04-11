// main.cpp
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "Creating bureaucrat with valid grade (42):" << std::endl;
        Bureaucrat bureaucrat1("John", 42);
        std::cout << bureaucrat1 << std::endl;
        
        std::cout << "\nTrying to create bureaucrat with too high grade (0):" << std::endl;
        try {
            Bureaucrat bureaucrat2("Jane", 0);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\nTrying to create bureaucrat with too low grade (151):" << std::endl;
        try {
            Bureaucrat bureaucrat3("Jack", 151);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\nTesting grade manipulation:" << std::endl;
        Bureaucrat bureaucrat4("Alice", 10);
        std::cout << "Initial: " << bureaucrat4 << std::endl;
        
        bureaucrat4.incrementGrade();
        std::cout << "After increment: " << bureaucrat4 << std::endl;
        
        bureaucrat4.decrementGrade();
        std::cout << "After decrement: " << bureaucrat4 << std::endl;
        
        std::cout << "\nTesting grade boundaries:" << std::endl;
        Bureaucrat bureaucrat5("Bob", 1);
        std::cout << "Highest grade: " << bureaucrat5 << std::endl;
        
        try {
            std::cout << "Trying to increment highest grade:" << std::endl;
            bureaucrat5.incrementGrade();
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        Bureaucrat bureaucrat6("Charlie", 150);
        std::cout << "Lowest grade: " << bureaucrat6 << std::endl;
        
        try {
            std::cout << "Trying to decrement lowest grade:" << std::endl;
            bureaucrat6.decrementGrade();
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}
