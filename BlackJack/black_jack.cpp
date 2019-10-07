// A small black jack game. Nothing big here, pass by

#include "black_jack.hpp"

//
// Created by jomar on 05/03/19.
//

namespace  BlackJackCondition
{
    /// A few possibilites of conditions in this black jack game
    // TODO: Necessity? Or fanciness? hmm
    enum BlackJackCondition
    {
        HIT, /// < Hit.
        STAND, /// < Stand, therefore, accepting the actual result and waiting for the dealer play
        BUSTED, /// < Busted from the game. Whenever the player reaches a value greater than the actual 21 points limit
        WIN, /// < Well, winner? heh
        DEALER_WIN /// < Lost after the dealer play. Equals to busted condition
    };
}

size_t getTotalPoints(std::vector<Card> & deckCard)
{
    size_t totalPoints = 0;
    for (auto card : deckCard)
    {
        totalPoints += getCardValue(card);
    }

    return totalPoints;
}

/// Checks for H or h (hit)  and S or s (stand). It does not accept any other character than the mentioned ones
/// @return If the user input an H, it will return true. If it's not H and yet S, it will return false
bool checkForHitOrStand()
{
    while (true)
{
    auto answer = new char[0];

        std::cin.get(answer[0]);

        std::cin.ignore(256, '\n');

        if (answer[0] != 'H' && answer[0] != 'h')
        {
            if (answer[0] != 'S' && answer[0] != 's')
            {
                std::cout << "\nUnknown command. Type H to hit or S to stand\n";
                continue;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
}

void playBlackJack(std::array<Card, deckLength> & deckCard)
{
    // Do the initial preparation for the black jack game

    // Creates the dealer deck, inserting the first card for it's deck.
    // TODO: Why the dealer have one card at start? ~ humming sound ~
    std::vector<Card> dealerDeck {};

    // Card pointer which will be used to go through the deck
    Card * getNextCard = nullptr;
    getNextCard = &deckCard[0];

    dealerDeck.push_back(*getNextCard);

    // Gets the next card, using the pointer abilities of arithmetic
    ++getNextCard;

    // Creates the player deck and inserts two cards. Those are counted on the total points for the game
    // onwards
    std::vector<Card> playerDeck {};
    playerDeck.push_back(*getNextCard);

    ++getNextCard;

    playerDeck.push_back(*getNextCard);

    // A few variables to be sure of the result
    // TODO: Exchange this ugliness with something more palpable, like the enum at the start
    BlackJackCondition::BlackJackCondition condition = BlackJackCondition::HIT;


    // Keeps asking the player to adds cards
    // and, keeps informing them from the result of their pick.
    // A for loop is used just to be sure to stop if the card length is
    // achieved
    for (size_t totalCardsAsOfNow = 0; totalCardsAsOfNow < deckCard.size(); ++totalCardsAsOfNow)
    {
        // Reassure 0 to the total in each loop
        size_t totalPoints = 0;

        // Goes through the player deck thus calculating the total
        // points in its deck
        totalPoints = getTotalPoints(playerDeck);

        if (totalPoints > 21)
        {
            // If you busted, the program will say so,
            // and will finish the game through the busted variable
            std::cout << "You busted!\n";
            condition = BlackJackCondition::BUSTED;
            break;
        }

        std::cout << "Your total points is " << totalPoints << "\n";
        std::cout << "<H>it or <S>tand? ";


        // A simple type X and Y. Expecting the player to type the designated word
        // to proceed(H - hit and S - stand)
        // nothing fancy and eye catching in this loop
        if (checkForHitOrStand())
        {
            condition = BlackJackCondition::STAND;
            break;
        }

        // Gets the next card
        ++getNextCard;

        // Prints it's result and continues the loop just like it should
        std::cout << "You got a ";
        printCard(*getNextCard);
        std::cout << "\n";

        playerDeck.push_back(*getNextCard);
    }

    // The dealer times to shine is here
    // After the stand condition the dealer will, and should, play after all
    if (condition == BlackJackCondition::STAND)
    {
        // TODO: Well, there's no dealer play! DO IT!
        std::cout << "Starting the dealer play\n";

        std::uniform_int_distribution<std::mt19937_64::result_type> distribution{1, 4};

        std::random_device generator;
        std::mt19937_64 mt{generator()};

        unsigned int plays = distribution(mt);

        for (unsigned int i = 0; i < plays; ++i) {
            std::cout << "Dealer total points is " << getTotalPoints(dealerDeck) << "\n";

            ++getNextCard;

            std::cout << "The dealer got a ";
            printCard(*getNextCard);
            std::cout << "\n";

            dealerDeck.push_back(*getNextCard);

            if (getTotalPoints(dealerDeck) > 21)  {
                std::cout << "dealer got busted! \n";
                condition = BlackJackCondition::WIN;
                break;
            } else if (getTotalPoints(playerDeck) < getTotalPoints(dealerDeck)) {
                std::cout << "His score is greater than yours.";
                condition = BlackJackCondition::DEALER_WIN;
                break;
            } else {
                condition = BlackJackCondition::WIN;
            }
        }

        if (condition == BlackJackCondition::WIN) {
            std::cout << "You won!";
        } else if (condition == BlackJackCondition::DEALER_WIN) {
            std::cout << "You lost!";
        }
    }
    // Ends the game if busted. TODO: Maybe add a possibility to re-ask for another game?
    // FIXME: Implementation should probably be done outside of this function after all. Right?
    else if (condition == BlackJackCondition::BUSTED)
    {
        return;
    }
    else
    {

    }
}
