#ifndef GAME_HEADER
#define GAME_HEADER

#include <conio.h>
#include <cstdlib>
#include <string>
#include <iostream>

class Game {
public:
    void draw ();
    void update ();
    void event ();
    void Clear ();

    bool GameState ();

private:
    bool if_GameOver = false;

    int taily[100], tailx[100], ntail = 0;

    int height = 20, width = 30, score = 0;
    int snake_y = height / 2, snake_x = width / 2, fruit_y = rand() % height, fruit_x = rand() % width;

    enum KeyInput{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    KeyInput key;

};
#endif // GAME_HEADER
