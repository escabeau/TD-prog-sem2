#include "ex4.hpp"
#include <iostream>
#include <algorithm>

int search(const std::vector<int>& vec, int value) {
    int left = 0;
    int right = static_cast<int>(vec.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (vec[middle] == value) {
            return middle;
        } else if (vec[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

void test_search() {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 2, 2, 3, 4, 8, 12}, 8},
        {{1, 2, 3, 3, 6, 14, 12, 15}, 15},
        {{2, 2, 3, 4, 5, 8, 12, 15, 16}, 16},
        {{5, 6, 7, 8, 9, 10, 11, 12, 13}, 6},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10}
    };

    for (auto& [vec, val] : tests) {
        std::sort(vec.begin(), vec.end());
        int idx = search(vec, val);
        std::cout << "Recherche de " << val << " : ";
        if (idx != -1) {
            std::cout << "trouve a l'indice " << idx << "\n";
        } else {
            std::cout << "non trouve\n";
        }
        std::cout << std::endl;
    }
}
