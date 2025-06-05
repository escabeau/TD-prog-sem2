
#include <iostream>
#include "ex1.hpp"
#include "ex2.hpp"
#include "ex3.hpp"



int main() {
    std::vector<int> vec = generateRandomVector(20);
    
    std::cout << "Vecteur initial : ";
    displayVector(vec);

    int input;
    std::cout << "Entrez un nombre a rechercher : ";
    std::cin >> input;

    if (findNumber(vec, input)) {
        std::cout << input << " est present dans le vecteur." << std::endl;
    } else {
        std::cout << input << " n'est pas present dans le vecteur." << std::endl;
    }

    int count = countOccurrences(vec, input);
    std::cout << input << " apparait " << count << " fois." << std::endl;

    sortVector(vec);
    std::cout << "Vecteur trie : ";
    displayVector(vec);

    int sum = sumVector(vec);
    std::cout << "Somme des elements : " << sum << std::endl;



    //ex2


    std::cout << "\n=== Exercice 2 ===" << std::endl;
    std::string phrase;
    std::cin.ignore(); // vider le buffer après saisie précédente
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, phrase);

    size_t len = firstWordLength(phrase);
    std::cout << "Longueur du premier mot : " << len << std::endl;

    std::vector<std::string> mots = split_string(phrase);
    std::cout << "Mots extraits : ";
    for (const auto& mot : mots) {
        std::cout << "[" << mot << "] ";
    }
    std::cout << std::endl;

    //ex3 et lambda test

    std::cout << "\n=== Exercice 3 ===" << std::endl;
    std::string mot;
    std::cout << "Entrez un mot pour tester s'il est un palindrome : ";
    std::getline(std::cin, mot);

    if (isPalindrome(mot)) {
        std::cout << mot << " est un palindrome." << std::endl;
    } else {
        std::cout << mot << " n'est pas un palindrome." << std::endl;
    }

    std::vector<int> sampleVec = {1, 2, 3, 4, 5, 6};

    int sumSquares = sumOfSquares(sampleVec);
    std::cout << "Somme des carres : " << sumSquares << std::endl;

    int productEvens = productOfEvens(sampleVec);
    std::cout << "Produit des elements pairs : " << productEvens << std::endl;





    return 0;
}
