#include "stringhelper.h"


Stringhelper::Stringhelper(int widthh)
{
    width = widthh;
}

void Stringhelper::printFullLine(void)
{
    for(int i = 0; i <= width; i++)
    {
        std::cout << "#";
        
    }
        std::cout << std::endl; 

}

void Stringhelper::printEmptyLine(void)
{
    std::cout << "#";
    for(int i = 0; i<= (width-2); i++)
    {
        std::cout << " ";
    }
    std::cout << "#" << std::endl;
}

void Stringhelper::printText(std::string text)
{
    if (text.length() % 2 == 0)
    {
        text = text + " ";
    }   
    int diff = (width - text.length()-2);
    std::cout << "#";
    for(int i = 0; i <= (diff/2); i++)
    {
        std::cout << " ";
    }
    std::cout << text;
    for(int i = 0; i <= (diff/2); i++)
    {
        std::cout << " ";
    }
    std::cout << "#" << std::endl;

}