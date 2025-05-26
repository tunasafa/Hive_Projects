// ScalarConverter.cpp
#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty() || literal.back() != 'f') return false;
    
    bool hasDot = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return hasDot;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;
    
    bool hasDot = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+') i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return hasDot;
}

void ScalarConverter::convertChar(const std::string& literal) {
    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    printValues(c, i, f, d);
}

void ScalarConverter::convertInt(const std::string& literal) {
    long l = strtol(literal.c_str(), NULL, 10);
    if (l < INT_MIN || l > INT_MAX) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    
    int i = static_cast<int>(l);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printValues(c, i, f, d);
}

void ScalarConverter::convertFloat(const std::string& literal) {
    std::string floatStr = literal.substr(0, literal.length() - 1);
    char* endptr;
    float f = strtof(floatStr.c_str(), &endptr);
    
    if (*endptr != '\0' || (f == HUGE_VALF || f == -HUGE_VALF)) {
        handlePseudoLiterals(literal);
        return;
    }
    
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);
    printValues(c, i, f, d);
}

void ScalarConverter::convertDouble(const std::string& literal) {
    char* endptr;
    double d = strtod(literal.c_str(), &endptr);
    
    if (*endptr != '\0' || (d == HUGE_VAL || d == -HUGE_VAL)) {
        handlePseudoLiterals(literal);
        return;
    }
    
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    printValues(c, i, f, d);
}

void ScalarConverter::printValues(char c, int i, float f, double d) {
    // Char
    if (i < 0 || i > 127) {
        std::cout << "char: impossible\n";
    } else if (!isprint(c)) {
        std::cout << "char: Non displayable\n";
    } else {
        std::cout << "char: '" << c << "'\n";
    }
    
    // Int
    if (d < INT_MIN || d > INT_MAX || std::isnan(d)) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << i << "\n";
    }
    
    // Float
    std::cout << "float: " << f;
    if (f - static_cast<int>(f) == 0 && !std::isnan(f) && !std::isinf(f)) {
        std::cout << ".0f\n";
    } else {
        std::cout << "f\n";
    }
    
    // Double
    std::cout << "double: " << d;
    if (d - static_cast<int>(d) == 0 && !std::isnan(d) && !std::isinf(d)) {
        std::cout << ".0\n";
    } else {
        std::cout << "\n";
    }
}

void ScalarConverter::handlePseudoLiterals(const std::string& literal) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    
    if (literal == "nanf" || literal == "nan") {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    } else if (literal == "+inff" || literal == "+inf") {
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    } else if (literal == "-inff" || literal == "-inf") {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    } else {
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: empty input\n";
        return;
    }
    
    if (isChar(literal)) {
        convertChar(literal);
    } else if (isInt(literal)) {
        convertInt(literal);
    } else if (isFloat(literal)) {
        convertFloat(literal);
    } else if (isDouble(literal)) {
        convertDouble(literal);
    } else {
        handlePseudoLiterals(literal);
    }
}
