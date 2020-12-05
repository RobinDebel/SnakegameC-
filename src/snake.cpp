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
  switch(direction) 
  {
    case Direction::LEFT: canvas->draw_symbol(x(), y(), '<'); break;
    case Direction::RIGHT: canvas->draw_symbol(x(), y(), '>'); break;
    case Direction::UP: canvas->draw_symbol(x(), y(), '^'); break;
    case Direction::DOWN: canvas->draw_symbol(x(), y(), 'v'); break;
  }
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

void Snake::down(void) {
  direction = Direction::DOWN;
}

void Snake::up(void) {
  direction = Direction::UP;
}

void Snake::left(void) {
  direction = Direction::LEFT;
}

void Snake::right(void) {
  direction = Direction::RIGHT;
}