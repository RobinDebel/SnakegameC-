#pragma once

class Snake
{
public:
    void CreateSnake(int width, int height);

public:
    void SnakeDown();
    void SnakeUp();
    void SnakeLeft();
    void SnakeRight();

public:
    int GetXSnake();
    int GetYSnake();
};