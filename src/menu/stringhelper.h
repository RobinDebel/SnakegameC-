#pragma once

#include <string>
#include <iostream>

class Stringhelper
{
    public:
     Stringhelper(int width);
     

    public: 
     void printFullLine(void);
     void printEmptyLine(void);
     void printSelectedText(std::string text);
     void printText(std::string text);

    private:
    int width = 0;
    
};