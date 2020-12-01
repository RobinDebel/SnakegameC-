#include <iostream>
#include "input.h"
#include <cstdlib>
#include <conio.h>    // Windows only

using namespace std;

Keys::Key Keys::pressed_key(void)
{
    int key = getch();
    
    switch (key)
    {
        case 72: return Key::UP;
        case 80: return Key::DOWN;
        case 75: return Key::LEFT;
        case 77: return Key::RIGHT;
        case 13: return Key::ENTER;
        case 27: return Key::ESCAPE;
    }
    return Key::ESCAPE;
}