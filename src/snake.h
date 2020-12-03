#pragma once

#include "entity.h"
#include "canvas.h"

class Snake: public Entity{
    
    private:
    enum class Direction{
        UP, LEFT, RIGHT, DOWN
    };

    public:
    Snake(int x, int y);
    
    public:
    void render(Canvas*canvas);
    void update(void);

    public:
    void next_position(int * x, int * y);

    public:
    void up(void);
    void down(void);
    void left(void);
    void right(void);

    private:
    void move(Direction direction);

    private:
    Direction direction = Direction::RIGHT;
    
}