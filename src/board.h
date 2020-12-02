#pragma once
#include <string>


class DrawBoard{
    public: 
    void CreateBoard();

    public:
    void PrintBoard(void);

    public:
    int GetWidth();
    int getHeight();

    private:
    std::string BoardString;
    const int width = 50;
    const int height = 25;

};
