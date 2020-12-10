#include "menu.h"
#include <iostream>
#include "unistd.h"
// to exit std::exit(EXIT_SUCCESS);

Menu::Menu(void)
{
    showStartMenu();
    showSelectionMenu();


};


void Menu::showStartMenu(void)
{
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("Welcome");
    stringhelper.printText("To the wonderfull world of snake");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("You can select your choice");
    stringhelper.printText("By using the up and down key.");
    stringhelper.printText("Lock in by pressing Enter.");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
}