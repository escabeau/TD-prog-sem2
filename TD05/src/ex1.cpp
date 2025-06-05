#include "ex1.hpp"

// Hachage 
size_t hachage_folding(const std::string& chaine, size_t max) {
    size_t hachage = 0;
    for (char caractere : chaine) {
        hachage = (hachage + static_cast<size_t>(caractere)) % max;
    }
    return hachage;
}

// Hachage ordre 
size_t hachage_folding_ordre(const std::string& chaine, size_t max) {
    size_t hachage = 0;
    for (size_t i = 0; i < chaine.size(); ++i) {
        hachage = (hachage + static_cast<size_t>(chaine[i]) * (i + 1)) % max;
    }
    return hachage;
}

// Hachage poly
size_t hachage_polynomial(const std::string& chaine, size_t p, size_t m) {
    size_t hachage = 0;
    size_t puissance = 1;

    for (char caractere : chaine) {
        hachage = (hachage + (static_cast<size_t>(caractere) * puissance) % m) % m;
        puissance = (puissance * p) % m;
    }

    return hachage;
}
