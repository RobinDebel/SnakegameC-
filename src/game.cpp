#include "game.h"
#include "unistd.h"
#include <time.h>
#include <stdlib.h>
#include "controller.h"   // Keyboard input


Game::Game(void)
    :snake(30, 15) {

    srand(time(NULL));
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
    candy = Candy(1+rand()%(WIDTH-2), 1+rand()%(HEIGHT-2));
}

void Game::game_loop(void)
{
    int counter = 0;
    while(!gameOver)
    {
        counter++;
        if (counter >= 2)
        {
            update();
            counter = 0;
        }
        render();
        usleep(100'000); //1s
    }
}

void Game::tailupdate()
{
    
    if (tails.size() >= 3)
    {
        deletelast_tail(1);
        
    }
    addpiece_tail();
    


}

void Game::addpiece_tail()
{
    tails.push_back(Tail(snake.x(),snake.y()));
}

void Game::deletelast_tail(int amount)
{
    for (int i=0; i < amount; i++)
    {
        tails.erase(tails.begin());
    }
}

void Game::update(void)
{   
    process_keyboard_input();
    tailupdate();
    snake.update();
    check_for_collisions_with_walls();

    //collision with walls
    

    //collision with candy
    check_for_collisions_with_candy();

}

void Game::render(void)
{   
    canvas.clear();
    snake.render(&canvas);

    for(auto wall : walls)
    {
        wall.render(&canvas);
    }

    for(auto tail : tails)
    {
        tail.render(&canvas);
    }

    candy.render(&canvas);

    canvas.output_to_terminal();
}

void Game::check_for_collisions_with_walls(void)
{
    for(auto wall : walls)
    {
        if(wall.x() == snake.x() && wall.y() == snake.y())
        {
            gameOver = true;
        }
    }
}

void Game::check_for_collisions_with_candy(void)
{
    bool candyeaten = false;
    if(snake.x() == candy.x() && snake.y() == candy.y())
    {
        candyeaten = true;
    }

    if (candyeaten)
    {
        candy = Candy(1+rand()%(WIDTH-2), 1+rand()%(HEIGHT-2));
    }
}

void Game::process_keyboard_input(void) {
  Controller::Key pressedKey = Controller::get_key_press();

  switch (pressedKey) {
    case Controller::Key::DOWN: snake.down(); break;
    case Controller::Key::UP: snake.up(); break;
    case Controller::Key::LEFT: snake.left(); break;
    case Controller::Key::RIGHT: snake.right(); break;
  }
}