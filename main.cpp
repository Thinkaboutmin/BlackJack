#include <iostream>
#include <array>
#include "BlackJack/black_jack.hpp"

int main() {
    std::array<Card, deckLength> deckCard = createDeck();
    shuffleDeck(deckCard);
    playBlackJack(deckCard);

    return 0;
}