// Contains the ranks and suits enumerators.

//
// Created by jomar on 02/03/19.
//

#ifndef CARDGAME_SUITS_RANKS_HPP
#define CARDGAME_SUITS_RANKS_HPP

/// All available ranks for the card game. It contains a LENGTH value for loops
enum class Ranks {
    RANK_TWO, ///< Rank two
    RANK_THREE, ///< Rank three
    RANK_FOUR, ///< Rank four
    RANK_FIVE, ///< < Rank five
    RANK_SIX, ///< Rank six
    RANK_SEVEN, ///< Rank seven
    RANK_EIGHT, ///< Rank eight
    RANK_NINE, ///< Rank nine
    RANK_TEN, ///< Rank ten
    RANK_JACK, ///< Rank jack
    RANK_QUEEN, ///< Rank queen
    RANK_KING, ///< Rank king
    RANK_ACE, ///< Rank ace
    LENGTH ///< The total of ranks
};


/// All available suits for the card game. It contains a LENGTH value for loops
enum class Suits {
    SUIT_CLUBS, ///< Suit club
    SUIT_DIAMONDS, ///< Suit diamonds
    SUIT_HEARTS, ///< Suit hearts
    SUIT_SPADES, ///< Suit spades
    LENGTH ///<  The total of suits
};

/// A card structure which contains the rank and suit of the card
struct Card
{
    Ranks rank;
    Suits suit;
};


#endif
