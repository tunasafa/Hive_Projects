// main.cpp
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;
    
    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Deserialized value: " << deserialized->value << std::endl;
    
    if (&data == deserialized) {
        std::cout << "Success: Pointers match!" << std::endl;
    } else {
        std::cout << "Error: Pointers don't match!" << std::endl;
    }
    
    return 0;
}
