cmake_minimum_required(VERSION 3.13)
project(CardGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(CardGame main.cpp Utilities/functions.cpp Utilities/functions.hpp Utilities/suits_ranks.hpp BlackJack/black_jack.cpp BlackJack/black_jack.hpp)