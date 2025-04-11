// main.cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat high("Director", 5);
        Bureaucrat medium("Manager", 50);
        Bureaucrat low("Intern", 140);

        std::cout << "\nCreated bureaucrats:" << std::endl;
        std::cout << high << std::endl;
        std::cout << medium << std::endl;
        std::cout << low << std::endl;

        // Create forms with different requirements
        Form easyForm("Basic Report", 100, 120);
        Form mediumForm("Budget Request", 50, 70);
        Form hardForm("Top Secret Clearance", 5, 10);

        std::cout << "\nCreated forms:" << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << mediumForm << std::endl;
        std::cout << hardForm << std::endl;

        // Test signing forms
        std::cout << "\nTesting form signing:" << std::endl;
        
        // Everyone can sign the easy form
        low.signForm(easyForm);
        std::cout << easyForm << std::endl;
        
        // Only medium and high can sign the medium form
        medium.signForm(mediumForm);
        std::cout << mediumForm << std::endl;
        
        // Only high can sign the hard form
        low.signForm(hardForm);  // This should fail
        medium.signForm(hardForm);  // This should fail
        high.signForm(hardForm);
        std::cout << hardForm << std::endl;

        // Test form with invalid grades
        std::cout << "\nTesting form with invalid grades:" << std::endl;
        try {
            Form invalidForm("Invalid Form", 0, 100);  // Too high grade
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        try {
            Form invalidForm("Invalid Form", 50, 160);  // Too low grade
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}
