// Functions for the main deck card thing

//
// Created by jomar on 02/03/19.
//

#include <random>
#include "functions.hpp"

void printCard(const Card & card)
{
    switch (card.rank)
    {
        case Ranks::RANK_TWO:
            std::cout << "2";
            break;
        case Ranks::RANK_THREE:
            std::cout << "3";
            break;
        case Ranks::RANK_FOUR:
            std::cout << "4";
            break;
        case Ranks::RANK_FIVE:
            std::cout << "5";
            break;
        case Ranks::RANK_SIX:
            std::cout << "6";
            break;
        case Ranks::RANK_SEVEN:
            std::cout << "7";
            break;
        case Ranks::RANK_EIGHT:
            std::cout << "8";
            break;
        case Ranks::RANK_NINE:
            std::cout << "9";
            break;
        case Ranks::RANK_TEN:
            std::cout << "T";
            break;
        case Ranks::RANK_JACK:
            std::cout << "J";
            break;
        case Ranks::RANK_QUEEN:
            std::cout << "Q";
            break;
        case Ranks::RANK_KING:
            std::cout << "K";
            break;
        case Ranks::RANK_ACE:
            std::cout << "A";
            break;
        case Ranks::LENGTH:
            return;
    }

    switch (card.suit)
    {

        case Suits::SUIT_CLUBS:
            std::cout << "C";
            break;
        case Suits::SUIT_DIAMONDS:
            std::cout << "D";
            break;
        case Suits::SUIT_HEARTS:
            std::cout << "H";
            break;
        case Suits::SUIT_SPADES:
            std::cout << "S";
            break;
        case Suits::LENGTH:
            return;
    }

}

std::array<Card, deckLength> createDeck()
{
    std::array<Card, deckLength> deckOfCards{};

    size_t indexTracker = 0;
    // Goes through each suit and then each rank to fulfill the deck
    for (size_t suit = 0; suit < static_cast<size_t>(Suits::LENGTH); ++suit) {
        for (size_t rank = 0; rank < static_cast<size_t>(Ranks::LENGTH); ++rank) {
            // Initialize the card struct and addresses each of the values to the deck at the end
            Card card{};
            card.suit = static_cast<Suits>(suit);
            card.rank = static_cast<Ranks>(rank);

            deckOfCards.at(indexTracker) = card;

            // Keeps track of the deck index, so that the deck card can actually be defined
            ++indexTracker;
        }
    }

    return deckOfCards;
}

void shuffleDeck(std::array<Card, deckLength> & deckOfCards)
{
    std::uniform_int_distribution<std::mt19937_64::result_type> deckShufflerDistribution(0, 51);

    // Swaps cards from the first to the last in a p-random way
    for (size_t index = 0; index < deckLength; ++index)
    {
        std::random_device rnd;
        std::mt19937_64 mt{rnd()};
        size_t auxShuffle = deckShufflerDistribution(mt);

        swapCard(&deckOfCards.at(index), &deckOfCards.at(auxShuffle));
    }
}

void swapCard(Card * toSwap, Card * swapper) {
    if (&toSwap == &swapper)
    {
        return;
    }

    Card auxCard = *toSwap;

    *toSwap = *swapper;
    *swapper = auxCard;
}

int getCardValue(const Card &card)
{
    int cardValue = 0;

    switch (card.rank)
    {

        case Ranks::RANK_TWO:
            cardValue = 2;
            break;
        case Ranks::RANK_THREE:
            cardValue = 3;
            break;
        case Ranks::RANK_FOUR:
            cardValue = 4;
            break;
        case Ranks::RANK_FIVE:
            cardValue = 5;
            break;
        case Ranks::RANK_SIX:
            cardValue = 6;
            break;
        case Ranks::RANK_SEVEN:
            cardValue = 7;
            break;
        case Ranks::RANK_EIGHT:
            cardValue = 8;
            break;
        case Ranks::RANK_NINE:
            cardValue = 9;
            break;
        case Ranks::RANK_TEN:
        case Ranks::RANK_JACK:
        case Ranks::RANK_QUEEN:
        case Ranks::RANK_KING:
            cardValue = 10;
            break;
        case Ranks::RANK_ACE:
            cardValue = 11;
            break;
        case Ranks::LENGTH:
            cardValue = -1;
            break;
    }

    return cardValue;
}

void printDeck(const std::array<Card, deckLength> &deckCard) {
    for (auto card : deckCard)
    {
        printCard(card);
        std::cout << " ";
    }
}
