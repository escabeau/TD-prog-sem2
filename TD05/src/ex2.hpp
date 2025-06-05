#pragma once

#include <vector>
#include <string>
#include <random>

enum class Insect;

std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int seed = std::random_device{}()
);

std::vector<float> probabilities_from_count(std::vector<int> const& counts);

void analyse_insects();

// --- ex1 truc
// size_t folding_string_ordered_hash(std::string const& s, size_t max);
// size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m);
