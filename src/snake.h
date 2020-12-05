#pragma once

#include "direction.h"
#include "canvas.h"
#include "entity.h"

class Snake : public Entity{

    public:
        Snake(int x, int y);



    public:
    void render(Canvas * canvas);
    void update();

    public:
    void down(void);
    void up(void);
    void left(void);
    void right(void);

    Direction direction = Direction::LEFT;

};