#include "menu.h"
#include <iostream>
#include "unistd.h"
#include "../game.h"
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
            case 1://main menu
            showStartMenu();
            showSelectionMenu();
            break;
            case 2:// instructions
            showInstructionMenu();
            break;
            case 3: //highscore
            showHighscoreMenu();
            break;
            
        }
        usleep(100'000); //100ms
    }
    Game game;
};


void Menu::keyInput(void)
{
    Controller::Key pressedKey = Controller::get_key_press();

    switch(pressedKey)
    {
        case Controller::Key::DOWN: 
            if(cursor == 4)
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
                cursor = 4;
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
    if (selection == 1)
    {
        switch(cursor)
        {
            case 1:
                selection = 0;
            break;
            case 2:
                selection = 2;
            break;
            case 3:
                selection = 3;
            break;
            case 4:
                std::exit(EXIT_SUCCESS);
            break;
        }
    }else
    {
        selection = 1;
    }

}

void Menu::showStartMenu(void)
{
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("Welcome");
    stringhelper.printText("to the wonderfull world of snake.");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("You can select your choice by");
    stringhelper.printText("using the up and down key.");
    stringhelper.printText("Select your choice by pressing Enter.");
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
      stringhelper.printText("The Highscore");
      stringhelper.printText("Exit");
      break;
      case 2:
      stringhelper.printText("Play");
      stringhelper.printSelectedText("Instructions");
      stringhelper.printText("The Highscore");
      stringhelper.printText("Exit");
      break;
      case 3:
      stringhelper.printText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printSelectedText("The Highscore");
      stringhelper.printText("Exit");
      break;
      case 4:
      stringhelper.printText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printText("The Highscore");
      stringhelper.printSelectedText("Exit");
      break;
    }
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();

}

void Menu::showInstructionMenu(void)
{
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("Instructions:");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("You are a hungry snake who loves eating candy.");
    stringhelper.printText("Ofcourse eating candy makes you get bigger.");
    stringhelper.printText("Running the snake into his own tail");
    stringhelper.printText("or the wall will make him die");
    stringhelper.printText("Try to make the snake as big as you possibly can!");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("You can control the snake by using the arrow keys");
    stringhelper.printEmptyLine();
    stringhelper.printText("The walls looks like this: '#'");
    stringhelper.printText("The snake like this: '<OOOOO'");
    stringhelper.printText("And the delicious looks like this: 'x'");
    stringhelper.printEmptyLine();
    stringhelper.printSelectedText("Go back to the main menu by pressing enter!");
    stringhelper.printFullLine();
}

void Menu::showHighscoreMenu(void)
{
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("Highscore = 100");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printSelectedText("Go back to the main menu by pressing enter!");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();

}