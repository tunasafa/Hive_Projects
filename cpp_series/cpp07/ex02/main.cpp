#include <iostream>
#include <string>
#include "Array.hpp"

void testBasicFunctionality() {
    std::cout << "=== Basic Functionality Test ===" << std::endl;
    
    // Test default constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    // Test parameterized constructor
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    // Initialize with values
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    // Display values
    std::cout << "Array contents: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
}

void testCopyConstructor() {
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    
    Array<std::string> original(3);
    original[0] = "Hello";
    original[1] = "World";
    original[2] = "C++";
    
    Array<std::string> copy(original);
    
    std::cout << "Original: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;
    
    // Modify original to test deep copy
    original[0] = "Modified";
    
    std::cout << "After modifying original[0]:" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
}

void testAssignmentOperator() {
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    
    Array<int> arr1(4);
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i + 1;
    }
    
    Array<int> arr2(2);
    arr2[0] = 99;
    arr2[1] = 88;
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "arr1 size: " << arr1.size() << ", contents: ";
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "arr2 size: " << arr2.size() << ", contents: ";
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    // Assignment
    arr2 = arr1;
    
    std::cout << "After arr2 = arr1:" << std::endl;
    std::cout << "arr2 size: " << arr2.size() << ", contents: ";
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    // Test self-assignment
    arr1 = arr1;
    std::cout << "Self-assignment works (no crash)" << std::endl;
}

void testExceptionHandling() {
    std::cout << "\n=== Exception Handling Test ===" << std::endl;
    
    Array<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    // Valid access
    std::cout << "Valid access arr[1]: " << arr[1] << std::endl;
    
    // Test out of bounds access
    try {
        std::cout << "Trying to access arr[5] (out of bounds)..." << std::endl;
        std::cout << arr[5] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test negative index (will be converted to large unsigned)
    try {
        std::cout << "Trying to access arr[-1] (negative index)..." << std::endl;
        std::cout << arr[static_cast<unsigned int>(-1)] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test empty array access
    Array<int> emptyArr;
    try {
        std::cout << "Trying to access emptyArr[0]..." << std::endl;
        std::cout << emptyArr[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testDifferentTypes() {
    std::cout << "\n=== Different Types Test ===" << std::endl;
    
    // Test with double
    Array<double> doubleArr(3);
    doubleArr[0] = 3.14;
    doubleArr[1] = 2.71;
    doubleArr[2] = 1.41;
    
    std::cout << "Double array: ";
    for (unsigned int i = 0; i < doubleArr.size(); i++) {
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;
    
    // Test with custom type (using string as example)
    Array<std::string> stringArr(2);
    stringArr[0] = "Template";
    stringArr[1] = "Programming";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < stringArr.size(); i++) {
        std::cout << "\"" << stringArr[i] << "\" ";
    }
    std::cout << std::endl;
}

void testDefaultInitialization() {
    std::cout << "\n=== Default Initialization Test ===" << std::endl;
    
    Array<int> intArr(5);
    std::cout << "Default initialized int array: ";
    for (unsigned int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;
    
    Array<std::string> stringArr(3);
    std::cout << "Default initialized string array: ";
    for (unsigned int i = 0; i < stringArr.size(); i++) {
        std::cout << "\"" << stringArr[i] << "\" ";
    }
    std::cout << std::endl;
}

int main() {
    testBasicFunctionality();
    testCopyConstructor();
    testAssignmentOperator();
    testExceptionHandling();
    testDifferentTypes();
    testDefaultInitialization();
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}
