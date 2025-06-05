#include "utils.hpp"
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <random>
#include <vector>

bool is_sorted(const std::vector<int>& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

std::vector<int> generate_random_vector(size_t n, int max_value) {
    std::vector<int> v(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, max_value);
    for (auto& x : v) x = dis(gen);
    return v;
}
