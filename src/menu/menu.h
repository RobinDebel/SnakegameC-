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
     void readHighscoresFile(void);

    private:
    unsigned int cursor = 1;
    unsigned int selection = 1;
    int count = 0;
    bool fullscore = false;
    int width = 60;
    std::vector<std::string> topscores;
    Stringhelper stringhelper = Stringhelper(width); 
     

};