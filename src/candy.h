#pragma once

#include "canvas.h"
#include "entity.h"

class Candy : public Entity{
    public:
    Candy(int x, int y);

    public:
    void render(Canvas * canvas);
};