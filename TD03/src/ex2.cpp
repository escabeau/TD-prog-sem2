#include "ex2.hpp"

size_t quick_sort_partition(std::vector<int>& vec, size_t left, size_t right, size_t pivot) {
    std::swap(vec[pivot], vec[right]);
    size_t store = left;
    for (size_t i = left; i < right; ++i) {
        if (vec[i] < vec[right]) {
            std::swap(vec[i], vec[store]);
            ++store;
        }
    }
    std::swap(vec[store], vec[right]);
    return store;
}

void quick_sort(std::vector<int>& vec, size_t left, size_t right) {
    if (left >= right) return;
    size_t pivot = left + (right - left) / 2;
    size_t mid = quick_sort_partition(vec, left, right, pivot);
    if (mid > 0) quick_sort(vec, left, mid - 1);
    quick_sort(vec, mid + 1, right);
}

void quick_sort(std::vector<int>& vec) {
    if (!vec.empty()) quick_sort(vec, 0, vec.size() - 1);
}

void merge_sort_merge(std::vector<int>& vec, size_t left, size_t mid, size_t right) {
    std::vector<int> left_vec(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> right_vec(vec.begin() + mid + 1, vec.begin() + right + 1);
    size_t i = 0, j = 0, k = left;
    while (i < left_vec.size() && j < right_vec.size()) {
        vec[k++] = (left_vec[i] < right_vec[j]) ? left_vec[i++] : right_vec[j++];
    }
    while (i < left_vec.size()) vec[k++] = left_vec[i++];
    while (j < right_vec.size()) vec[k++] = right_vec[j++];
}

void merge_sort(std::vector<int>& vec, size_t left, size_t right) {
    if (left >= right) return;
    size_t mid = left + (right - left) / 2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge_sort_merge(vec, left, mid, right);
}

void merge_sort(std::vector<int>& vec) {
    if (!vec.empty()) merge_sort(vec, 0, vec.size() - 1);
}
