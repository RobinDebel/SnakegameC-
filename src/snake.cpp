#include "snake.h"

Snake::Snake(int x, int y)
 : Entity(x,y){
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
        case Direction::LEFT: Entity::move(x()-1,y()); break;
        case Direction::RIGHT: Entity::move(x()+1,y()); break;
        case Direction::UP: Entity::move(x(),y()-1); break;
        case Direction::DOWN: Entity::move(x(),y()+1); break;
    }
}

void Snake::down(void) 
{
  if (direction != Direction::UP)
  {
    direction = Direction::DOWN;
  }
    
}

void Snake::up(void) 
{
  if(direction != Direction::DOWN)
  {
    direction = Direction::UP;
  }
}

void Snake::left(void) {
  if(direction != Direction::RIGHT)
  {
    direction = Direction::LEFT;
  }
  
}

void Snake::right(void) {
    if(direction != Direction::LEFT)
  {
    direction = Direction::RIGHT;
  }
}