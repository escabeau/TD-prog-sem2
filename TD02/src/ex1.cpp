#include "ex1.hpp"

#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>
#include <stdexcept>
#include <iostream>


std::vector<std::string> split_string(std::string const& s) {
    std::istringstream in(s);
    return std::vector<std::string>(
        std::istream_iterator<std::string>(in),
        std::istream_iterator<std::string>()
    );
}



bool is_digit(std::string const& s) {
    for (char i : s) {
        if (!std::isdigit(i)) {
            return false;
        }
    }
    return true;
}



bool is_floating(std::string const& s) {
    int dot_count = 0;
    for (char i : s) {
        if (i == '.') {
            dot_count++;
            if (dot_count > 1) return false;
        } else if (!std::isdigit(i)) {
            return false;
        }
    }
    return !s.empty();
}



float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> stack;

    for (std::string const& i : tokens) {
        if (is_floating(i)) {
            stack.push(std::stof(i));
        } else {
            float rightOperand = stack.top(); stack.pop();
            float leftOperand = stack.top(); stack.pop();
            float result {
                i == "+" ? leftOperand + rightOperand :
                i == "-" ? leftOperand - rightOperand :
                i == "*" ? leftOperand * rightOperand :
                i == "/" ? leftOperand / rightOperand : 0
            };
            stack.push(result);
        }
    }
    if (stack.size() != 1) {
        std::cout << "Erreur dans l'expression en NPI" << std::endl;
        return 0;
    } else {
        return stack.top();
    }
}
