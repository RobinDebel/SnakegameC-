#pragma once

#include "snake.h"
#include <vector>
#include "wall.h"
#include "candy.h"
#include "canvas.h"
#include "tail.h"
#include <string>

class Game {

    public:
    Game(void);

    private:
    void create_walls(void);
    void create_candy(void);
        
    private:
    void game_loop(void);
    void update(void);
    void render(void);

    private:
    void check_for_collisions_with_walls(void);
    void check_for_collisions_with_candy(void);
    void check_for_collisions_with_tail(void);
    void process_keyboard_input(void);
    void tailupdate(void);
    void addpiece_tail(void);
    void deletelast_tail(void);
    
    private:
    void ask_username(void);
    void sort_scores(void);
    void add_score(void);
    
    
    private:
    
    Snake snake;
    Candy candy = Candy(1,1);
    std::string username = "";
    std::vector<Wall> walls;
    std::vector<Tail> tails;
    

    Canvas canvas;

    bool gameOver = false;
    bool candyeaten = false;
    long unsigned int tailsize = 3;
    unsigned int score = 0;
    const static int WIDTH = 60;
    const static int HEIGHT = 30;


};