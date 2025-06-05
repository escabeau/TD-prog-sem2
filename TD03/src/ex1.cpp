#include "ex1.hpp"

void bubble_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
        }
    }
}

void selection_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < vec.size(); ++j)
            if (vec[j] < vec[min_idx])
                min_idx = j;
        std::swap(vec[i], vec[min_idx]);
    }
}
