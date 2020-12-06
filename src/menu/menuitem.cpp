#include "menuitem.h"

MenuItem::MenuItem(std::string text)
{
    menutext = text;
}

std::string MenuItem::return_text(void)
{
    return menutext;   
}