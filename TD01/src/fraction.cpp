#include "fraction.hpp"
#include "utils.hpp"
#include <numeric>

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    os << f.numerateur << "/" << f.denominateur;
    return os;
}

bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction f1Simplifie = simplifier(f1);
    Fraction f2Simplifie = simplifier(f2);
    return f1Simplifie.numerateur == f1Simplifie.numerateur &&
           f1Simplifie.denominateur == f2Simplifie.denominateur;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2); 
}

//  +=
Fraction& Fraction::operator+=(Fraction const& other) {
    numerateur = numerateur * other.denominateur + other.numerateur * denominateur;
    denominateur *= other.denominateur;

    *this = simplifier(*this); 
    return *this;
}

//  -=
Fraction& Fraction::operator-=(Fraction const& other) {
    numerateur = numerateur * other.denominateur - other.numerateur * denominateur;
    denominateur *= other.denominateur;

    *this = simplifier(*this); 
    return *this;
}

//  *=
Fraction& Fraction::operator*=(Fraction const& other) {
    numerateur *= other.numerateur;
    denominateur *= other.denominateur;

    *this = simplifier(*this); 
    return *this;
}

// /=
Fraction& Fraction::operator/=(Fraction const& other) {
    numerateur *= other.denominateur;
    denominateur *= other.numerateur;

    *this = simplifier(*this); 
    return *this;
}


float Fraction::to_float() const {
    return static_cast<float>(numerateur) / static_cast<float>(denominateur);
}


Fraction::operator float() const {
    return to_float();
}

// valeur absolue de la fraction
Fraction Fraction::abs() const {
    return Fraction{std::abs(numerateur), std::abs(denominateur)};
}

// arrondi supérieur de la fraction
Fraction Fraction::ceil() const {
    int result = static_cast<int>(std::ceil(to_float()));
    return Fraction{result, 1}; 
}

// arrondi inférieur de la fraction
Fraction Fraction::floor() const {
    int result = static_cast<int>(std::floor(to_float()));
    return Fraction{result, 1}; 
}

// 
Fraction Fraction::round() const {
    int result = static_cast<int>(std::round(to_float()));
    return Fraction{result, 1}; 
}



Fraction operator+(Fraction const& f1, Fraction const& f2) {
    Fraction result = f1;
    result += f2; //  +=
    return result;
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    Fraction result = f1;
    result -= f2; //  -=
    return result;
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    Fraction result = f1;
    result *= f2; //  *=
    return result;
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    Fraction result = f1;
    result /= f2; //  /=
    return result;
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    
    return f1.numerateur * f2.denominateur < f2.numerateur * f1.denominateur;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return !(f2 < f1); 
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f2 < f1; 
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2); 
}

//  +
Fraction operator+(Fraction const& f, int const i) {
    return f + Fraction{i, 1}; 
}

Fraction operator+(int const i, Fraction const& f) {
    return f + i; 
}

//  -
Fraction operator-(Fraction const& f, int const i) {
    return f - Fraction{i, 1}; 
}

Fraction operator-(int const i, Fraction const& f) {
    return Fraction{i, 1} - f; 
}

//  *
Fraction operator*(Fraction const& f, int const i) {
    return f * Fraction{i, 1};
}

Fraction operator*(int const i, Fraction const& f) {
    return f * i; 
}

//  /
Fraction operator/(Fraction const& f, int const i) {
    return f / Fraction{i, 1}; 
}

Fraction operator/(int const i, Fraction const& f) {
    return Fraction{i, 1} / f; 
}

// Ancienne version des opérateurs (commentée)
// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplifier({
//         f1.numerateur * f2.denominateur + f2.numerateur * f1.denominateur,
//         f1.denominateur * f2.denominateur
//     });
// }

// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplifier({
//         f1.numerateur * f2.denominateur - f2.numerateur * f1.denominateur,
//         f1.denominateur * f2.denominateur
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplifier({
//         f1.numerateur * f2.numerateur,
//         f1.denominateur * f2.denominateur
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplifier({
//         f1.numerateur * f2.denominateur,
//         f1.denominateur * f2.numerateur
//     });
// }