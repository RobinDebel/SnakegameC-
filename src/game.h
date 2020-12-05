#pragma once

#include "snake.h"
class Game {

    public:
    Game(void)
        : snake(30,15) {
            
    }

    private:
    Snake snake;


};