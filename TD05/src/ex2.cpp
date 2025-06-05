#include "ex2.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <random>
#include <functional>
#include <numeric>
#include <cmath>
#include <iomanip>


enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};


static const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};


static const std::unordered_map<Insect, std::string> insect_to_string {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};


static const std::vector<int> expected_insect_counts {
    75, 50, 100, 20, 400, 150, 60, 10, 40, 90, 5
};


std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int seed
) {
    std::default_random_engine random_engine(seed);
    std::discrete_distribution<size_t> distribution(insect_probabilities.begin(), insect_probabilities.end());

    std::vector<std::pair<Insect, int>> observations;
    observations.reserve(number_of_observations);

    for (size_t i = 0; i < number_of_observations; ++i) {
        size_t random_insect_index = distribution(random_engine);
        Insect random_insect = insect_values[random_insect_index];

        if (!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i--;
        } else {
            observations.emplace_back(random_insect, 1);
        }
    }

    return observations;
}


std::vector<float> probabilities_from_count(std::vector<int> const& counts) {
    int sum = std::accumulate(counts.begin(), counts.end(), 0);
    std::vector<float> probabilities;
    probabilities.reserve(counts.size());

    if (sum == 0) {
        probabilities.assign(counts.size(), 0.f);
        return probabilities;
    }

    for (int count : counts) {
        probabilities.push_back(static_cast<float>(count) / sum);
    }

    return probabilities;
}


void analyse_insects() {
    std::cout << std::fixed << std::setprecision(3);

    std::vector<float> expected_probabilities = probabilities_from_count(expected_insect_counts);


    auto observations = get_insect_observations(10000, expected_probabilities, 12345);


    std::unordered_map<Insect, int> counter;
    for (Insect insect : insect_values) {
        counter[insect] = 0;
    }

    for (const auto& [insect, quantity] : observations) {
        counter[insect] += quantity;
    }


    std::cout << "=== Observed count ===\n";
    for (Insect insect : insect_values) {
        std::cout << insect_to_string.at(insect) << " : " << counter[insect] << '\n';
    }


    std::vector<int> observed_counts;
    for (Insect insect : insect_values) {
        observed_counts.push_back(counter[insect]);
    }


    std::vector<float> observed_probabilities = probabilities_from_count(observed_counts);

    std::cout << "\n=== Observed probabilities ===\n";
    for (size_t i = 0; i < insect_values.size(); ++i) {
        std::cout << insect_to_string.at(insect_values[i]) << " : "
                  << observed_probabilities[i] << '\n';
    }


    std::cout << "\n=== Probabilities of observed insects vs expected probabilities ===\n";
    float threshold = 0.01f;
    for (size_t i = 0; i < insect_values.size(); ++i) {
        std::string name = insect_to_string.at(insect_values[i]);
        float observed = observed_probabilities[i];
        float expected = expected_probabilities[i];
        float diff = std::abs(observed - expected);
        std::string status = (diff <= threshold) ? "OK" : "BAD";

        std::cout << name << " : " << observed << " vs " << expected << " " << status << '\n';
    }
}
