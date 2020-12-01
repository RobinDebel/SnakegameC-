#pragma once
#include <string>


class DrawBoard{
    public: 
    void CreateBoard();

    public:
    void PrintBoard(void);

    private:
    std::string BoardString;
    const int width = 50;
    const int height = 25;

};
