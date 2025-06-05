
#include "ex1.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>

std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);

    for (auto& num : vec) {
        num = dist(gen);
    }
    return vec;
}

void displayVector(const std::vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool findNumber(const std::vector<int>& vec, int number) {
    return std::find(vec.begin(), vec.end(), number) != vec.end();
}

int countOccurrences(const std::vector<int>& vec, int number) {
    return std::count(vec.begin(), vec.end(), number);
}

void sortVector(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

int sumVector(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}
