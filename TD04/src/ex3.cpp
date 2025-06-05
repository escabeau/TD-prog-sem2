#include "ex3.hpp"
#include <algorithm>
#include <numeric>

bool isPalindrome(const std::string& str) {
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int sumOfSquares(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0, [](int sum, int val) {
        return sum + val * val;
    });
}

int productOfEvens(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, [](int prod, int val) {
        return (val % 2 == 0) ? prod * val : prod;
    });
}