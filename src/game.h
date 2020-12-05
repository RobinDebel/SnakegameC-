#pragma once

#include "snake.h"
#include <vector>
#include "wall.h"
#include "candy.h"
#include "canvas.h"

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
    Snake snake;
    Candy candy = Candy(1,1);
    std::vector<Wall> walls;

    Canvas canvas;

    bool gameOver = false;
    const static int WIDTH = 60;
    const static int HEIGHT = 30;


};