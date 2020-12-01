#include <iostream>
#include "board.h"
#include "terminal.h"
#include "game.h"
#include "input.h"

using namespace std;

void Game::RunGame(){
    DrawBoard bord;
    Terminal terminal;
    Keys::Key key;
    bord.CreateBoard();

    while(1)
    {
    // terminal.ClearTerminal();
    bord.PrintBoard();
    key = Keys::pressed_key();
    cout << key <<endl;
    }
}