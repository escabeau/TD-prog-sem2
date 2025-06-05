
#ifndef EX1_HPP
#define EX1_HPP

#include <vector>

std::vector<int> generateRandomVector(size_t size);
void displayVector(const std::vector<int>& vec);
bool findNumber(const std::vector<int>& vec, int number);
int countOccurrences(const std::vector<int>& vec, int number);
void sortVector(std::vector<int>& vec);
int sumVector(const std::vector<int>& vec);

#endif 
