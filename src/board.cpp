#include <iostream>
#include "board.h"

using namespace std;

void DrawBoard::CreateBoard()
{
    for (int i = 0; i < height; i++)
    {
        BoardString += "#";
        for (int j = 0; j < width - 2; j++)
        {
            if (i == 0 || i == height - 1)
            {
                BoardString += "#";
            }
            else
            {
                BoardString += " ";
            }
        }
        BoardString += "#\n";
    }
};

void DrawBoard::PrintBoard()
{
    cout << BoardString << endl;
};

int DrawBoard::GetWidth()
{
    return width;
}

int DrawBoard::getHeight()
{
    return height;
}
