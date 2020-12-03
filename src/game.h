#pragma once

#include <vector>
#include "snake.h"
#include "candy.h"
#include "wall.h"
#include "canvas.h"


class Game{
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
    void check_collision_with_walls(void);
    void check_collision_with_candy(void);
    void check_collision_with_tail(void);
    void process_keyboard_input(void);

    private:
    const static int WIDTH = 60;
    const static int HEIGHT = 30;

    bool gameOver = false; 



}