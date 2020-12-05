#pragma once

#include "snake.h"
#include <vector>
#include "wall.h"
#include "candy.h"
#include "canvas.h"
#include "tail.h"

class Game {

    public:
    Game(void);

    private:
    void create_walls(void);
    void create_candy(void);
        
    private:
    void game_loop(void);
    void update(void);
    void render(void);

    private:
    void check_for_collisions_with_walls(void);
    void check_for_collisions_with_candy(void);
    void process_keyboard_input(void);
    void tailupdate(void);
    void addpiece_tail();
    void deletelast_tail(int amount);

    
    private:
    Snake snake;
    Candy candy = Candy(1,1);
    std::vector<Wall> walls;
    std::vector<Tail> tails;

    Canvas canvas;

    bool gameOver = false;
    const static int WIDTH = 60;
    const static int HEIGHT = 30;


};