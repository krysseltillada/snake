#include "Game.h"

/// implementation file 

bool Game::state = true;

void Game::run ()
{
    draw ();
    input ();
    Clear ();
}

void Game::set_name (std::string &i) {
    name = i;
}

bool Game::Game_state()
{
    return state;
}

void Game::Clear ()
{
    system("cls");
}

void Game::draw ()
{
    update_world();
    draw_world();
}

void Game::rand_spawn_bait() {
     bait_y = rand() % (height - range_y);
     bait_x = rand() % (width - range_x);
}

void Game::reset_spawn_snake() {
    snake_x = width / 2;
    snake_y = height / 2;
}

void Game::check_collision (char p_world[][70], size_t &y, size_t &x) {
    if (p_world[snake_y][snake_x] == world_bounds[bait_y][bait_x]) {
                rand_spawn_bait();
                ++score;
    } else if (((snake_y >= -4 && snake_y <= 18) && snake_x == 0) || ((snake_x >= -5 && snake_x <= 69) && snake_y == 0)
               || ((snake_y >= -4 && snake_y <= 18) && snake_x == 69) ||  ((snake_x >= -5 && snake_x <= 69) && snake_y == 19)) {
        GameOver();
    }

}

void Game::GameOver()
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

void Game::reset_score()
{
    score = 0;
}

void Game::reset () {
    reset_score();
    reset_spawn_snake();
    rand_spawn_bait();
}

void Game::update_world ()
{
    for (size_t z = 0; z != height; ++z) {
        for (size_t n = 0; n != width; ++n) {

             world[snake_y][snake_x] = '0';
             world_bounds[snake_y][snake_x] = 'x';

             world[bait_y][bait_x] = 'x';
             world_bounds[bait_y][bait_x] = 'x';

             check_collision(world, z, n);

             world[z][n] = ' ';

             if ((z == 0 && n == n) || (z == 19 && n == n))  {
                world[z][n] = '#';
                world_bounds[z][n] = '0';
             }

             if ((z == z && n == 0) || (z == z && n == 69)) {
                world[z][n] = '#';
                world_bounds[z][n] = '0';
             }
        }
    }

}

void Game::draw_world ()
{
    for (size_t draw_y = 0; draw_y != height; ++draw_y) {
        for (size_t draw_x = 0; draw_x != width; ++draw_x) {
            std::cout << world[draw_y][draw_x];
        }
        std::cout << std::endl;
    }

    std::cout << name << ": " << score << std::endl;
}

void Game::input ()
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
