
#include "ex2.hpp"
#include <algorithm>

size_t firstWordLength(const std::string& str) {
    auto const is_space = [](char letter){ return letter == ' '; };

    auto it = std::find_if_not(str.begin(), str.end(), is_space); // début du 1er mot
    auto end = std::find_if(it, str.end(), is_space);             // fin du 1er mot

    return std::distance(it, end);
}

std::vector<std::string> split_string(const std::string& str) {
    auto const is_space = [](char c) { return c == ' '; };
    std::vector<std::string> result;

    auto it = str.begin();

    while (it != str.end()) {
        it = std::find_if_not(it, str.end(), is_space);
        if (it == str.end()) break;

        // fin du mot
        auto word_end = std::find_if(it, str.end(), is_space);

        result.emplace_back(it, word_end);  

        it = word_end;
    }

    return result;
}
