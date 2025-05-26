#include <iostream>
#include <string>
#include "iter.hpp"

// Test functions for different types
void printInt(const int& x) {
    std::cout << x << " ";
}

void printString(const std::string& s) {
    std::cout << "\"" << s << "\" ";
}

void doubleValue(int& x) {
    x *= 2;
}

void toUpper(std::string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

// Template function to test with iter
template<typename T>
void printValue(const T& value) {
    std::cout << "[" << value << "] ";
}

int main() {
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test with integer array
    std::cout << "\n1. Testing with integers:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    // Modify array using iter
    iter(intArray, intSize, doubleValue);
    std::cout << "After doubling: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    // Test with string array
    std::cout << "\n2. Testing with strings:" << std::endl;
    std::string stringArray[] = {"hello", "world", "cpp", "templates"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Original strings: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    // Modify strings using iter
    iter(stringArray, stringSize, toUpper);
    std::cout << "After toUpper: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    // Test with template function
    std::cout << "\n3. Testing with template function:" << std::endl;
    double doubleArray[] = {3.14, 2.71, 1.41, 1.73};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Double array: ";
    iter(doubleArray, doubleSize, printValue<double>);
    std::cout << std::endl;
    
    // Test edge cases
    std::cout << "\n4. Testing edge cases:" << std::endl;
    
    // Empty array (length 0)
    std::cout << "Empty array test: ";
    iter(intArray, 0, printInt);
    std::cout << "(nothing should print)" << std::endl;
    
    // NULL pointer test
    std::cout << "NULL pointer test: ";
    int* nullPtr = 0;
    iter(nullPtr, 5, printInt);
    std::cout << "(nothing should print)" << std::endl;
    
    // Single element array
    std::cout << "Single element: ";
    int single = 42;
    iter(&single, 1, printInt);
    std::cout << std::endl;
    
    return 0;
}
