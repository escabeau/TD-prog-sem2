#include "utils.hpp"
#include <cmath>


int pgcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int reste {a % b};
        a = b;
        b = reste;
    }
    return a;
}


Fraction simplifier(Fraction const& f) {
    const int diviseur { pgcd(f.numerateur, f.denominateur) };

    return {
        f.numerateur / diviseur,
        f.denominateur / diviseur
    };
}

void simplifier_ref(Fraction& f) {
    const int diviseur { pgcd(f.numerateur, f.denominateur) };
    f.numerateur /= diviseur;
    f.denominateur /= diviseur;
}
// recursive version
// int gcd(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//
//     return gcd(b, a % b);
// }
// ternary operator version
// int gcd(unsigned int a, unsigned int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }