#include "tail.h"

Tail::Tail(int x, int y)
    : Entity(x,y)
    {

    }

void Tail::render(Canvas * canvas)
{
    canvas ->draw_symbol(x(),y(),'O');
}
