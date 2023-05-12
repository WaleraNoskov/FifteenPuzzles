#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include <vector>
#include "Fiveteens.h"

class GUI{
    private:
        
        Fiveteens *fiveteens;
        void DrawCell(int y, int x, short num);
        
    public:
        struct Keys {
            char up;
            char right;
            char down;
            char left;
            char restart;
            char quit;
            char help;
        } keys;
        void DisplayKeysCalibration();
        void DisplayConfirmRestart();
        void DisplayConfirmQuit();
        void DisplayHelp();
        void DisplayWon();
        void DisplayFiveteens();
        GUI(Fiveteens *fiveteensItem);
};

#endif /* GUI_hpp */
