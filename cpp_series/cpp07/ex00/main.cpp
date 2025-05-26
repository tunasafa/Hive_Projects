#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {
    // Test with integers
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    // Test with strings
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    
    // Additional tests for edge cases
    std::cout << "\n--- Additional Tests ---" << std::endl;
    
    // Test with equal values
    int x = 5, y = 5;
    std::cout << "Equal values test:" << std::endl;
    std::cout << "min(5, 5) = " << ::min(x, y) << std::endl;
    std::cout << "max(5, 5) = " << ::max(x, y) << std::endl;
    
    // Test with doubles
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Before swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
    ::swap(d1, d2);
    std::cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
    
    return 0;
}
