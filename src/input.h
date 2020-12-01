#pragma once

class Keys{
    public: enum Key {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ENTER,
        ESCAPE
    };

    static Key pressed_key(void);
};