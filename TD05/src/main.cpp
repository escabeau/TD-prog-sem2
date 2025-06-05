#include <iostream>
#include <unordered_map>
#include "ex1.hpp"
#include "ex2.hpp"
#include "ex3.hpp"  // <-- ajout ex3

int main() {
    // === Exercice 1 ===
    /*
    std::string chaine1 = "abc";
    std::string chaine2 = "cba";
    size_t max = 1024;

    std::cout << "Hash (ordre non important) : " << hachage_folding(chaine1, max) << std::endl;
    std::cout << "Hash (ordre important)     : " << hachage_folding_ordre(chaine1, max) << std::endl;
    std::cout << "Hash (ordre important)     : " << hachage_folding_ordre(chaine2, max) << std::endl;

    std::cout << "Polynomial rolling hash : " << hachage_polynomial("abc", 31, 1'000'000'009) << std::endl;
    */

   // --- EXERCICE 2 ---

    analyse_insects();

    // --- EXERCICE 3 (ne fonctionne pas)---
   
    // Card carte1{CardKind::Heart, CardValue::Ace};
    // Card carte2{CardKind::Spade, CardValue::Queen};
    // Card carte3{CardKind::Heart, CardValue::Ace}; 

    // std::unordered_map<Card, std::string> deck;

    // deck[carte1] = "As de Coeur";
    // deck[carte2] = "Dame de Pique";

    // std::cout << "carte1 == carte3 ? " << (carte1 == carte3 ? "Oui" : "Non") << std::endl;

    // for (const auto& [carte, nom] : deck) {
    //     std::cout << nom << std::endl;
    // }

    return 0;
}
