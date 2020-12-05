#include "game.h"

Game::Game(void)
    :snake(30, 15) {

    create_walls();
    create_candy();

    render();
}

void Game::create_walls(void)
{
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            if (x==0 || y==0 || x == WIDTH -1 || y == HEIGHT -1 )
            {
                walls.push_back(Wall(x,y));
            }
        }
    }
}

void Game::create_candy(void)
{
    candy = Candy(10,15);
}

void Game::render(void)
{
    canvas.clear();
    for(auto wall : walls)
    {
        canvas.draw_symbol(wall.x(),wall.y(), '#');
    }

    canvas.draw_symbol(snake.x(),snake.y(), '>');

    canvas.draw_symbol(candy.x(),candy.y(), 'x');

    canvas.output_to_terminal();
}