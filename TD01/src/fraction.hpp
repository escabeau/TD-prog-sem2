#pragma once
#include <iostream>
#include <cmath> 

struct Fraction {
    int numerateur { 0 };
    int denominateur { 1 };

    
    float to_float() const;

    
    operator float() const;

   
    Fraction abs() const;
    Fraction ceil() const;
    Fraction floor() const;
    Fraction round() const;

    Fraction& operator+=(Fraction const& other);
    Fraction& operator-=(Fraction const& other);
    Fraction& operator*=(Fraction const& other);
    Fraction& operator/=(Fraction const& other);
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);


Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);
Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);
Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);