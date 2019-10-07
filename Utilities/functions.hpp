// Function declarations(prototype) for the card thing

//
// Created by jomar on 02/03/19.
//

#ifndef CARDGAME_FUNCTIONS_HPP
#define CARDGAME_FUNCTIONS_HPP

#include <array>
#include <iostream>
#include "suits_ranks.hpp"

/// Prints the card info with only two characters. One is the rank and the other is the suit
/// @param0 the card to be printed
/// @return nothing
void printCard(const Card & card);

// The size of the deck
constexpr size_t deckLength = 52;

/// Prints the deck of cards with according info from each card
/// @param0 the deck of cards
/// @return nothing
void printDeck(const std::array<Card, deckLength> & deckCard);

/// Returns an std::array with all the cards created
/// @return a entire deck of cards in order
std::array<Card, deckLength> createDeck();

/// Shuffles the entire card deck
/// @param0 the deck of cards to be shuffled
/// @return nothing
void shuffleDeck(std::array<Card, deckLength> & deckOfCards);

/// Swap cards
/// @param0 a card to be swapped
/// @param1 another card to swap
/// @return nothing because it will change directly
void swapCard(Card * toSwap, Card * swapper);

/// Get the raw value of the card
/// @param0 the card to get a value
/// @return value from the card
int getCardValue(const Card &card);

#endif //CARDGAME_FUNCTIONS_HPP
