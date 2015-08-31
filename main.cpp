#include "Game.h"

int main()
{
    Game game;

    while (!game.GameState()) {
        game.draw ();
        game.event ();
        game.update ();
        game.Clear ();
     }

    return 0;
}
