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
    next_position(&x,&y);
    Entity::move(x,y);
}

void Snake::next_position(int * x, int * y){
    *x= this->x();
    *y= this->y();
    switch(direction){
        case Direction::LEFT: *x = this->x() - 1; break;
        case Direction::RIGHT: *x = this->x() + 1; break;
        case Direction::UP: *y = this->y() - 1; break;
        case Direction::DOWN: *y = this->y() + 1; break;
    }    

}

void Snake::down(void){
    move(Direction::DOWN);
}

void Snake::up(void){
    move(Direction::UP);
}

void Snake::left(void){
    move(Direction::LEFT);
}

void Snake::right(void){
    move(Direction::RIGHT);
}

void Snake::move(Direction direction){
    this->direction = direction;
}