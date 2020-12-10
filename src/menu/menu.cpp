#include "menu.h"
#include <iostream>
#include "unistd.h"
#include "../controller.h"   // Keyboard input
// to exit std::exit(EXIT_SUCCESS);

Menu::Menu(void)
{
    while (selection > 0)
    {
        system("clear");
        keyInput();
        switch(selection)
        {   
            case 1:
            showStartMenu();
            showSelectionMenu();
            break;
        }
        usleep(100'000); //1s
    }
    
    


};


void Menu::showStartMenu(void)
{
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("Welcome");
    stringhelper.printText("to the wonderfull world of snake.");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("You can select your choice");
    stringhelper.printText("by using the up and down key.");
    stringhelper.printText("Select choice by pressing Enter.");
    stringhelper.printEmptyLine();
    stringhelper.printEmptyLine();
}

void Menu::showSelectionMenu(void)
{
  switch(cursor)
  {
      case 1:
      stringhelper.printSelectedText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printText("Exit");
      break;
      case 2:
      stringhelper.printText("Play");
      stringhelper.printSelectedText("Instructions");
      stringhelper.printText("Exit");
      break;
      case 3:
      stringhelper.printText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printSelectedText("Exit");
      break;
    }
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();

}

void Menu::keyInput(void)
{
    Controller::Key pressedKey = Controller::get_key_press();

    switch(pressedKey)
    {
        case Controller::Key::DOWN: 
            if(cursor == 3)
            {
                cursor = 1;
            }else
            {
                cursor++;
            }
            
        break;
        case Controller::Key::UP:
            if(cursor == 1)
            {
                cursor = 3;
            }else
            {
                cursor--;
            }
         break;

         case Controller::Key::ENTER:
            updateMenu();
         break;

    }
}

void Menu::updateMenu(void)
{
    switch(cursor)
    {
        case 1:
        selection = 0;
        break;
        case 2:

        break;
        case 3:
        std::exit(EXIT_SUCCESS);
        break;
    }
}