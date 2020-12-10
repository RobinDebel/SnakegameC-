#pragma once

#include <vector>
#include <string>
#include "stringhelper.h"

class Menu
{
    public:
     Menu(void);
     
    public:
     void showStartMenu(void);
     void showSelectionMenu(void);
     void keyInput(void);
     void updateMenu(void);
     void showInstructionMenu(void);
     void showHighscoreMenu(void);

    private:
    unsigned int cursor = 1;
    unsigned int selection = 1;
    int width = 60;
    Stringhelper stringhelper = Stringhelper(width); 
     

};