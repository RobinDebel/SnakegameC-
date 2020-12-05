#include "snake.h"

Snake::Snake(int x, int y)
{
_x = x;
_y = y;
}

int Snake::x(){
    return _x;
}

int Snake::y(){
    return _y;
}