#include "snake.h"

Snake::Snake(int x, int y)
    : Entity(x, y){

}

void Snake::render(Canvas*canvas){
    switch(direction){
        case Direction::LEFT: canvas->draw_symbol(x(), y(), '<'); break;
        case Direction::RIGHT: canvas->draw_symbol(x(), y(), '>'); break;
        case Direction::UP: canvas->draw_symbol(x(), y(), '^'); break;
        case Direction::DOWN: canvas->draw_symbol(x(), y(), 'v'); break;
    }
}

void Snake::update(void){
    int x = 0;
    int y = 0;
    Entity::move(x,y);
}