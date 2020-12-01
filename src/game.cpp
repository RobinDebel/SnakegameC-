#include <iostream>
#include "board.h"
#include "terminal.h"
#include "game.h"

using namespace std;

void Game::RunGame(){
    DrawBoard bord;
    Terminal terminal;
    terminal.ClearTerminal();
    bord.CreateBoard();
    bord.PrintBoard();
}