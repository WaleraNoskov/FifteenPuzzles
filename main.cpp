#include <iostream>
#include <ctime>
#include <ncurses.h>

#include "Fiveteens.h"
#include "GUI.hpp"

int main(int argc, const char * argv[]) {

    auto fiveteens = new Fiveteens();
    auto gui = new GUI(fiveteens);
    
    gui->DisplayKeysCalibration();
    
    while(true){
        if(fiveteens->CheckWon())
            gui->DisplayWon();
            
        gui->DisplayFiveteens();
    
        char pressed = getch();
        if(pressed == gui->keys.up)
            fiveteens->MoveUp();
        else if(pressed == gui->keys.right)
            fiveteens->MoveRight();
        else if(pressed == gui->keys.down)
            fiveteens->MoveDown();
        else if(pressed == gui->keys.left)
            fiveteens->MoveLeft();
        else if(pressed == gui->keys.restart)
            gui->DisplayConfirmRestart();
        else if(pressed == gui->keys.quit)
            gui->DisplayConfirmQuit();
        else if(pressed == gui->keys.help)
            gui->DisplayHelp();
        
    }

    return 0;
}
   
