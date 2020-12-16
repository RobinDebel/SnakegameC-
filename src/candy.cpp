#include "candy.h"

Candy::Candy(int x, int y)
  : Entity(x,y){

}

void Candy::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), 'x');
}
