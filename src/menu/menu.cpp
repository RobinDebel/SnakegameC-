#include "menu.h"
#include <iostream>
#include <fstream>
#include "unistd.h"
#include "../game.h"
#include "../controller.h"   // Keyboard input

Menu::Menu(void)
{
    while(true){
        readHighscoresFile();
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
                case 4:
                showSettingsMenu();
                break;
                
            }
            usleep(100'000); //100ms
        }
        Game game;
        selection = 1;
    }
};


void Menu::keyInput(void)
{
    Controller::Key pressedKey = Controller::get_key_press();

    switch(pressedKey)
    {
        case Controller::Key::DOWN: 
            if(cursor == 5)
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
                cursor = 5;
            }else
            {
                cursor--;
            }

            if(selection == 3)
            {
                fullscore = true;
            }
         break;

         case Controller::Key::ENTER:
            updateMenu();
            fullscore = false;
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
                selection = 4;
            break;
            case 5:
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
      stringhelper.printText("Highscores");
      stringhelper.printText("Settings");
      stringhelper.printText("Exit");
      break;
      case 2:
      stringhelper.printText("Play");
      stringhelper.printSelectedText("Instructions");
      stringhelper.printText("Highscores");
      stringhelper.printText("Settings");
      stringhelper.printText("Exit");
      break;
      case 3:
      stringhelper.printText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printSelectedText("Highscores");
      stringhelper.printText("Settings");
      stringhelper.printText("Exit");
      break;
      case 4:
      stringhelper.printText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printText("Highscores");
      stringhelper.printSelectedText("Settings");
      stringhelper.printText("Exit");
      break;
      case 5:
      stringhelper.printText("Play");
      stringhelper.printText("Instructions");
      stringhelper.printText("Highscores");
      stringhelper.printText("Settings");
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
    stringhelper.printText("or the wall will make him die.");
    stringhelper.printText("Try to make the snake as big as you possibly can!");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    stringhelper.printText("You can control the snake by using the arrow keys");
    stringhelper.printEmptyLine();
    stringhelper.printText("The walls looks like this: '#'");
    stringhelper.printText("The snake like this: '<OOOOO'");
    stringhelper.printText("And the delicious candy looks like this: 'x'");
    stringhelper.printEmptyLine();
    stringhelper.printSelectedText("Go back to the main menu by pressing enter!");
    stringhelper.printFullLine();
}

void Menu::showSettingsMenu(void)
{
    stringhelper.printText("You smell");
}

void Menu::showHighscoreMenu(void)
{
    count = 0;
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    if(!fullscore)
    {
    stringhelper.printText("The top 3 best scores are: ");
    }else
    {
        stringhelper.printText("All scores: ");
    }
    
    stringhelper.printEmptyLine();
    while(!fullscore && count < 3 && topscores.size() > count)
    {
        stringhelper.printText(topscores[count]);
        count++;
    }
    while(fullscore && count <= topscores.size() && topscores.size() > count)
    {
        stringhelper.printText(topscores[count]);
        count++;
    }
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();
    stringhelper.printEmptyLine();
    if(!fullscore)
    {
        stringhelper.printSelectedText("Show all scores by pressing arrowkey up.");
    }
    stringhelper.printSelectedText("Go back by pressing enter!");
    stringhelper.printEmptyLine();
    stringhelper.printFullLine();

}

void Menu::readHighscoresFile(void)
{
    topscores.clear();
    std::ifstream file;
    file.open("scoreboard.txt");
    std::string input;
    int count = 1;
    while (std::getline(file, input))
    {
        topscores.push_back(std::to_string(count) + ": " + input);
        count++;
    }
}