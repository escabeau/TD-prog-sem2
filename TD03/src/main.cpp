#include <iostream>
#include <vector>
#include <algorithm>

#include "ex1.hpp"
#include "ex2.hpp"
// #include "ex3.hpp"
// #include "ex4.hpp"

//QUESTIONS BIBLIOTHEQUE
//std::sort : très rapide, optimisé
//Bubble sort / Selection sort : lent, simple, pas efficace
//Quick sort / Merge sort : rapide


int main() {
    // Exercice 1 : tri itératif 
    
    std::vector<int> array1 {5, 3, 2, 4, 1};
    bubble_sort(array1);
    if (std::is_sorted(array1.begin(), array1.end())) std::cout << "Ex1 : tri bulle OK\n";
    selection_sort(array1);
    if (std::is_sorted(array1.begin(), array1.end())) std::cout << "Ex1 : tri selection OK\n";
    

    // Exercice 2 : tri récursif
    
    
    // std::vector<int> array2 {10, 7, 8, 9, 1, 5};
    // quick_sort(array2);
    // if (std::is_sorted(array2.begin(), array2.end())) std::cout << "Ex2 : quick_sort OK\n";

    // array2 = {10, 7, 8, 9, 1, 5};
    // merge_sort(array2);
    // if (std::is_sorted(array2.begin(), array2.end())) std::cout << "Ex2 : merge_sort OK\n";


    // // Exercice 3 : comparaison des algorithmes de tri
    // compare_sorts(10000, 100000);

    // Exercice 4 : recherche dichotomique 
    
    // test_search();
    

    return 0;
}