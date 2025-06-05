#pragma once
#include <functional>

enum class CardKind { Heart, Spade, Diamond, Club };
enum class CardValue { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const;
};


namespace std {
    template<>
    struct hash<Card>;
}