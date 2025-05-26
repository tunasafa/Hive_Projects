#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    // Default constructor - creates empty array
    Array() : _elements(0), _size(0) {}
    
    // Constructor with size parameter
    Array(unsigned int n) : _elements(0), _size(n) {
        if (n > 0) {
            _elements = new T[n]();  // () initializes with default values
        }
    }
    
    // Copy constructor
    Array(const Array& other) : _elements(0), _size(other._size) {
        if (_size > 0) {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
    }
    
    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            // Clean up existing memory
            delete[] _elements;
            
            // Copy from other
            _size = other._size;
            _elements = 0;
            
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = other._elements[i];
                }
            }
        }
        return *this;
    }
    
    // Destructor
    ~Array() {
        delete[] _elements;
    }
    
    // Subscript operator for access
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    // Const subscript operator
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    // Size function
    unsigned int size() const {
        return _size;
    }
};

#endif
