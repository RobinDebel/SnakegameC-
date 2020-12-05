#pragma once

#include "snake.h"
#include <vector>
#include "wall.h"

class Game {

    public:
    Game(void);

    private:
    void create_walls(void);
        
    private:
    Snake snake;
    std::vector<Wall> walls;

    const static int WIDTH = 60;
    const static int HEIGHT = 30;


};