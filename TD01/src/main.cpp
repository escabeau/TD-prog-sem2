#include <iostream>
#include "fraction.hpp"

int main() {
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

   
    std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;

  
    Fraction f3 = f1 + f2;
    std::cout << "f1 + f2 = " << f3 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;

    std::cout << "f1 += f2 : " << (f1 += f2) << std::endl;
    std::cout << "f1 -= f2 : " << (f1 -= f2) << std::endl;
    std::cout << "f1 *= f2 : " << (f1 *= f2) << std::endl;
    std::cout << "f1 /= f2 : " << (f1 /= f2) << std::endl;

    Fraction f4 { 1, 2 };
    float d1 = static_cast<float>(f4);
    std::cout << "f4 = " << f4 << ", float(f4) = " << d1 << std::endl;


    if (f1 == f2) {
        std::cout << f1 << " == " << f2 << std::endl;
    } else {
        std::cout << f1 << " != " << f2 << std::endl;
    }

    if (f1 < f2) {
        std::cout << f1 << " < " << f2 << std::endl;
    } else {
        std::cout << f1 << " > " << f2 << std::endl;
    }

    
    if (f1 <= f2) {
        std::cout << f1 << " <= " << f2 << std::endl;
    } else {
        std::cout << f1 << " >= " << f2 << std::endl;
    }

    return 0;
}