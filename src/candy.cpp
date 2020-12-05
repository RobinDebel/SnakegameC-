#include "candy.h"

Candy::Candy(int x, int y)
{
_x = x;
_y = y;
}

int Candy::x(){
    return _x;
}

int Candy::y(){
    return _y;
}

void Candy::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), 'x');
}
