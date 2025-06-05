#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"
#include "ex1.hpp"  // pour bubble_sort, selection_sort
#include "ex2.hpp"  // pour quick_sort, merge_sort
#include "utils.hpp"

void compare_sorts(size_t size = 10000, int max_val = 100000) {
    std::cout << "Génération d'un vecteur aléatoire de taille " << size << "...\n";
    auto original = generate_random_vector(size, max_val);

    {
        auto vec = original;
        ScopedTimer timer("std::sort");
        std::sort(vec.begin(), vec.end());
    }
    {
        auto vec = original;
        ScopedTimer timer("bubble_sort");
        bubble_sort(vec);
    }
    {
        auto vec = original;
        ScopedTimer timer("selection_sort");
        selection_sort(vec);
    }
    {
        auto vec = original;
        ScopedTimer timer("quick_sort");
        quick_sort(vec);
    }
    {
        auto vec = original;
        ScopedTimer timer("merge_sort");
        merge_sort(vec);
    }
}