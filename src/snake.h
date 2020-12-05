#pragma once

#include "direction.h"
#include "canvas.h"

class Snake{

    public:
        Snake(int x, int y);

    public:
        int x(void);
        int y(void);

    public:
    void render(Canvas * canvas);
    void update();

    public:
    void down(void);
    void up(void);
    void left(void);
    void right(void);


    private:
    int _x = 0;
    int _y = 0;
    
    
    
    Direction direction = Direction::LEFT;

};