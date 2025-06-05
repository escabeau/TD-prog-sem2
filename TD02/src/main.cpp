#include <iostream>
#include <string>
#include <vector>
#include "ex1.hpp"   
#include "ex2.hpp"   

int main() {
    std::string exp;
    std::cout << "Entrez votre expression NPI : ";
    std::getline(std::cin, exp);

    std::vector<std::string> tokens_exp = split_string(exp);
    std::vector<Token> tokens = tokenize(tokens_exp);
    float result = npi_evaluate(tokens);

    std::cout << exp << " = " << result << std::endl;

    return 0;
}
