#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    std::string input;

    std::cout << "snake game:" << std::endl
              << "----------"  << std::endl;

    std::cout << "enter your name: " << std::endl;

    std::getline (std::cin, input);

    game.set_name (input);

    while (game.Game_state()) { /// checks the game state
        game.run (); /// runs the  game
    }

    return 0;
}
