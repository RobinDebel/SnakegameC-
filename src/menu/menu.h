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

    private:
     int width = 40;
     
     Stringhelper stringhelper = Stringhelper(width); 
     

};