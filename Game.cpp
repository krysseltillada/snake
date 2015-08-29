#include "Game.h"

/// implementation file 

bool Game::state = true; /// state of the game

void Game::run () /// this runs the game
{
    draw (); /// draws the  world
    input (); /// gets the input from the user
    Clear (); // clears the screen
}

void Game::set_name (std::string &i) { /// sets the player name
    name = i;
}

bool Game::Game_state() /// returns the game state
{
    return state;
}

void Game::Clear () /// clears the whole console
{
    system("cls");
}

void Game::draw () /// draws the game
{
    update_world();
    draw_world();
}

void Game::rand_spawn_bait() { /// spawns the bait at a random position
     bait_y = rand() % (height - range_y);
     bait_x = rand() % (width - range_x);
}

void Game::reset_spawn_snake() { /// resets the snake position
    snake_x = width / 2;
    snake_y = height / 2;
}

void Game::check_collision (char p_world[][70], size_t &y, size_t &x) { /// this checks the collision
    if (p_world[snake_y][snake_x] == world_bounds[bait_y][bait_x]) { /// if the snake and the bait collides then
                rand_spawn_bait();
                ++score;
    } else if (((snake_y >= -4 && snake_y <= 18) && snake_x == 0) || ((snake_x >= -5 && snake_x <= 69) && snake_y == 0) /// if snake and the wall collides then
               || ((snake_y >= -4 && snake_y <= 18) && snake_x == 69) ||  ((snake_x >= -5 && snake_x <= 69) && snake_y == 19)) {
        GameOver(); /// Game over
    }

}

void Game::GameOver() /// message prompt to user if game over
{
    Clear();
    while (true) {
    std::cout << "game over (try again ?: y or n)" << std::endl;

    char key;

    std::cin >> key;

    switch (key) {
    case 'n': {
        exit (1);
    }
    case 'y': {
        reset();
        return;
    }
    default: {
        std::cout << "invalid input: " << std::endl;
        continue;
    }
    }
    }

}

void Game::reset_score() /// resets the  score
{
    score = 0;
}

void Game::reset () { //// restarts the game
    reset_score();
    reset_spawn_snake();
    rand_spawn_bait();
}

void Game::update_world () /// updates the world
{
    for (size_t z = 0; z != height; ++z) {
        for (size_t n = 0; n != width; ++n) {

             world[snake_y][snake_x] = '0'; /// spawns the snake
             world_bounds[snake_y][snake_x] = 'x'; /// generates a bounds

             world[bait_y][bait_x] = 'x'; /// spawns the bait
             world_bounds[bait_y][bait_x] = 'x'; /// generates a bounds

             check_collision(world, z, n); /// checks the collision

             world[z][n] = ' '; /// generates spaces

             if ((z == 0 && n == n) || (z == 19 && n == n))  { /// generates walls and bounds
                world[z][n] = '#';
                world_bounds[z][n] = '0';
             }

             if ((z == z && n == 0) || (z == z && n == 69)) { // generates walls and bounds
                world[z][n] = '#';
                world_bounds[z][n] = '0';
             }
        }
    }

}

void Game::draw_world () /// draws the world 
{
    for (size_t draw_y = 0; draw_y != height; ++draw_y) {
        for (size_t draw_x = 0; draw_x != width; ++draw_x) {
            std::cout << world[draw_y][draw_x];
        }
        std::cout << std::endl;
    }

    std::cout << name << ": " << score << std::endl;
}

void Game::input () /// gets the user input 
{
    char key = _getch();

    switch (key) {
    case 'w':
        snake_y -= velocity;
        break;
    case 'a':
        snake_x -= velocity;
        break;
    case 's':
        snake_y += velocity;
        break;
    case 'd':
        snake_x += velocity;
        break;
    default:
        std::cout << "invalid key " << std::endl;
        break;
    }
}
