#include "Game.h"

void Game::draw()
{
    for (int u_wall = 0; u_wall != width; ++u_wall)
        std::cout << "#";
    std::cout << std::endl;

    for (int y = 0; y != height; ++y) {
        for (int x = 0; x != width; ++x) {
                if (x == 0 || x == width - 1)
                    std::cout << "#";
                else if ( snake_y == y && snake_x == x)
                    std::cout << "0";
                else if (fruit_y == y && fruit_x == x)
                    std::cout << "x";
                else {
                        bool if_print = false;
                        for (int c = 0; c != ntail; ++c) {
                            if (taily[c] == y && tailx[c] == x) {
                                std::cout << "o";
                                if_print = true;
                            }
                        }
                            if(!if_print)
                                std::cout << " ";
                }
        }
        std::cout << std::endl;
    }

    for (int l_wall = 0; l_wall != width; ++l_wall)
        std::cout << "#";

    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void Game::event()
{
    if (kbhit()) {
        switch (getch()) {
        case 'w':
            key = UP;
            break;
        case 's':
            key = DOWN;
            break;
        case 'a':
            key = LEFT;
            break;
        case 'd':
            key = RIGHT;
            break;
        default:
            break;
        }
    }

}

void Game::update()
{
    int prevY = taily[0];
    int prevX = tailx[0];
    int prev2X, prev2Y;

    tailx[0] = snake_x;
    taily[0] = snake_y;

    for (int i = 1; i < ntail; ++i) {
        if (tailx[i] == snake_x && taily[i] == snake_y)
             if_GameOver = true;

        prev2X = tailx[i];
        prev2Y = taily[i];

        tailx[i] = prevX;
        taily[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (key) {
    case UP:
        --snake_y;
        break;
    case DOWN:
        ++snake_y;
        break;
    case LEFT:
        --snake_x;
        break;
    case RIGHT:
        ++snake_x;
        break;
    default:
        break;
    }

    if (snake_y > height - 1 || snake_y < 0 || snake_x > width - 2 || snake_x < 0) {
            if (snake_y > height - 1)
                snake_y = 0;
            else if (snake_y < 0)
                snake_y = height - 1;
            else if (snake_x > width - 1)
                snake_x = 0;
            else
                snake_x = width - 1;
    }
    else if (snake_y == fruit_y && snake_x == fruit_x) {
        fruit_y = rand() % height;
        fruit_x = rand() % width;
        score += 10;
        ++ntail;
    }

}

bool Game::GameState()
{
    return if_GameOver;
}

void Game::Clear ()
{
    system ("cls");
}

