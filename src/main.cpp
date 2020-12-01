//g++ main.cpp board.cpp terminal.cpp -o output


#include <iostream>
#include "board.h"
#include "terminal.h"

using namespace std;

int main(){
    DrawBoard bord;
    Terminal terminal;
    terminal.ClearTerminal();
    bord.CreateBoard();
    bord.PrintBoard();
}