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

void Snake::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), '>');
}

void Snake::update(void)
{
    switch(direction) 
    {
        case Direction::LEFT: _x--; break;
        case Direction::RIGHT: _x++; break;
        case Direction::UP: _y--; break;
        case Direction::DOWN: _y++; break;
    }
}