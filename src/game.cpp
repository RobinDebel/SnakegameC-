#include "game.h"
#include "unistd.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "controller.h"   // Keyboard input

Game::Game(void)
    :snake(30, 15) {

    srand(time(NULL));
    create_walls();
    create_candy();

    game_loop();
    add_score(); 
}

void Game::create_walls(void)
{
    if(false)
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
    else
    {
        get_playfield();
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
        
        usleep(50'000); //1s
        
    }
}



void Game::update(void)
{   
    process_keyboard_input();
    tailupdate();
    snake.update();

    check_for_collisions_with_walls();
    check_for_collisions_with_candy();
    check_for_collisions_with_tail();

}

void Game::render(void)
{   
    canvas.clear();

    for(auto tail : tails)
    {
        tail.render(&canvas);
    }

    snake.render(&canvas);

    for(auto wall : walls)
    {
        wall.render(&canvas);
    }

    candy.render(&canvas);

    canvas.output_to_terminal();

    std::cout << "Score: " << score << std::endl;
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

void Game::check_for_collisions_with_tail(void)
{
    for(auto tail : tails)
    {
        if(tail.x() == snake.x() && tail.y() == snake.y())
        {
            gameOver = true;
        }
    }
}

void Game::check_for_collisions_with_candy(void)
{
    
    if(snake.x() == candy.x() && snake.y() == candy.y())
    {
        candyeaten = true;
    }

    if (candyeaten)
    {
        candy = Candy(1+rand()%(WIDTH-2), 1+rand()%(HEIGHT-2));
        bool candyclear = true;
        do{
            candyclear = true;
            for(auto tail : tails)
            {
                if(tail.x() == candy.x() && tail.y() == tail.x())
                {
                    candyclear = false;
                    candy = Candy(1+rand()%(WIDTH-2), 1+rand()%(HEIGHT-2));
                }
            }
        }while(!candyclear);
    score++;
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

void Game::tailupdate(void)
{
    if (candyeaten)
    {
        tailsize += 3;
        candyeaten = false;
    }
    
    if (tails.size() >= tailsize)
    {
        deletelast_tail();
        
    }
    addpiece_tail();
    


}

void Game::addpiece_tail(void)
{
    tails.push_back(Tail(snake.x(),snake.y()));
}

void Game::deletelast_tail(void)
{
    
    tails.erase(tails.begin());
   
}

void Game::sort_scores(void)  // this uses linux commands to sort the scoreboard.txt file
{
    system("sort -nrk 2 scoreboard.txt > scoreboard2.txt && rm scoreboard.txt && mv scoreboard2.txt scoreboard.txt");
 }

void Game::add_score(void)
{
    ask_username();

    
    std::fstream file("scoreboard.txt", std::ios::app);
    file << username << " " << score << std::endl;
    file.close();

    sort_scores();
}

void Game::ask_username(void)
{
    system("clear");
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printSelectedText("Game Over");
    stringhelper.printEmptyLine();
    stringhelper.printText("Please give a nickname to be added on the scoreboard.");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    std::cout << "\n        Nickname: ";
    std::cin >> username;
}

void Game::get_playfield(void)
{
    walls.clear();
    std::ifstream file;
    file.open("playingfield.txt");
    std::string input;
    int line = 0;
    while (std::getline(file, input))
    {
        for(int i=0; i < WIDTH; i++)
        {
            if(input.at(i) == '#')
            {
                walls.push_back(Wall(i,line));
            }
        }
        line++;
    }
}