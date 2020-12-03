#pragma once

class Canvas{
    public:
    Canvas(void);

    public:
    void Clear(void);
    void draw_symbol(int x, int y, char symbol);

    public:
    void output_to_terminal(void);

    private:
    static const unsigned int WIDTH = 60;
    static const unsigned int HEIGHT = 30;
    char screen[WIDTH][HEIGHT];
};