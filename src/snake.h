#pragma once

#include "direction.h"

class Snake{

    public:
        Snake(int x, int y);

    public:
        int x(void);
        int y(void);


    private:
    int _x = 0;
    int _y = 0;

    Direction direction = Direction::LEFT;

};