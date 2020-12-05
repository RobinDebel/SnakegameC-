#include "game.h"
#include "unistd.h"

Game::Game(void)
    :snake(30, 15) {

    create_walls();
    create_candy();

    game_loop();
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

void Game::game_loop(void)
{
    while(!gameOver)
    {
        update();
        render();
        usleep(100'000); //1s
    }
}

void Game::update(void)
{
    snake.update();

    //collision with walls
    for(auto wall : walls)
    {
        if(wall.x() == snake.x() && wall.y() == snake.y())
        {
            gameOver = true;
        }
    }

    //collision with candy
    bool candyeaten = false;
    if(snake.x() == candy.x() && snake.y() == candy.y())
    {
        candyeaten = true;
    }

    if (candyeaten)
    {
        candy = 
    }

}

void Game::render(void)
{   
    canvas.clear();
    snake.render(&canvas);

    for(auto wall : walls)
    {
        wall.render(&canvas);
    }

    

    candy.render(&canvas);

    canvas.output_to_terminal();
}