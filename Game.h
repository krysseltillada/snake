#ifndef GAME_HEADER
#define GAME_HEADER

#include <conio.h> /// _getch ()
#include <cstdlib> /// rand()
#include <string> /// std::string
#include <iostream> /// std::cout; std::endl;

/// interface file

class Game {
public:
    void set_name (std::string &);
    void draw ();
    void reset_score ();
    void reset ();
    void rand_spawn_bait ();
    void reset_spawn_snake ();
    void update_world ();
    void draw_world ();
    void check_collision (char [][70], size_t &, size_t &);
    void input ();
    void Clear ();
    void GameOver ();
    void run ();

    bool Game_state ();

private:
    std::string name;

    static bool state;
    static constexpr size_t height = 20, width = 70;
    unsigned score = 0;

    char world [height][width];
    char world_bounds[height][width];

    int snake_x = width / 2, snake_y = height / 2;
    int range_y = 6, range_x = 10;

    int bait_x = rand() % (width - range_x), bait_y = rand() % (height - range_y);
    int velocity = 1;
};


#endif // GAME_HEADER
