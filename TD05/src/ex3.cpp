#include "ex3.hpp"

bool Card::operator==(const Card& other) const {
    return kind == other.kind && value == other.value;
}

namespace std {
    template<>
    struct hash<Card> {
        std::size_t operator()(const Card& c) const noexcept {
            return (static_cast<std::size_t>(c.kind) << 4) ^ static_cast<std::size_t>(c.value);
        }
    };
}
