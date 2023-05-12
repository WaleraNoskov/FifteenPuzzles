#include "GUI.hpp"
#include <ncurses.h>


Fiveteens fiveteens;
struct Keys{
    char up;
    char right;
    char down;
    char left;
    char restart;
    char quit;
    char help;
} keys;
        
void GUI::DrawCell(int y, int x, short num)
{
    if(num > 9)
        mvprintw(y+1, x+2, "%d", num);
    else if(num > 0)
        mvprintw(y+1, x+3, "%d", num);
    else
        return;
        
    mvhline(y, x, 0, 5);
    mvhline(y+2, x, 0, 5);
    mvvline(y, x, 0, y+2-y);
    mvvline(y, x+5, 0, y+2-y);
    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y+2, x, ACS_LLCORNER);
    mvaddch(y, x+5, ACS_URCORNER);
    mvaddch(y+2, x+5, ACS_LRCORNER);
}
    
void GUI::DisplayKeysCalibration(){
    int row{}, col{};
    getmaxyx(stdscr, row, col);
    
    erase();
    mvprintw(row/2, col/2 - 6, "Press UP key");
    keys.up = getch();
    mvprintw(row/2, col/2 - 7, "Press RIGHT key");
    keys.right = getch();
    mvprintw(row/2, col/2 - 7, "Press DOWN key");
    keys.down = getch();
    mvprintw(row/2, col/2 - 7, "Press LEFT key");
    keys.left = getch();
    
    keys.restart = 'r';
    keys.quit = 'q';
    keys.help = 'h';
}
        
void GUI::DisplayConfirmRestart(){
    int row{}, col{};
    getmaxyx(stdscr, row, col);
    
    erase();
    mvprintw(row/2 - 1, col/2 - 15, "Are you really want to restart?");
    mvaddch(row/2 +1, col/2 -4, 'N' | A_BOLD);
    mvaddch(row/2 +1, col/2 +4, 'Y' | A_BOLD);
    
    char confirmation = getch();
    if(confirmation == 'y' || confirmation == 'Y')
        fiveteens->Shuffle();
}
        
void GUI::DisplayConfirmQuit(){
    int row{}, col{};
    getmaxyx(stdscr, row, col);
    
    erase();
    mvprintw(row/2 -1, col/2 - 13, "Are you really want to quit?");
    mvaddch(row/2 +1, col/2 -4, 'N' | A_BOLD);
    mvaddch(row/2 +1, col/2 +4, 'Y' | A_BOLD);
    
    char confirmation = getch();
    if(confirmation == 'y' || confirmation == 'Y'){
        endwin();
        exit(0);
    }
}

void GUI::DisplayHelp(){
    int row{}, col{};
    getmaxyx(stdscr, row, col);
    
    erase();
    
    mvprintw(row/2 - 2, col/2 - 13, "Use ARROWS to move puzzles");
    
    mvaddch(row/2, col/2 -7, 'r' | A_BOLD);
    mvprintw(row/2, col/2 - 6, " for restart");
    
    mvaddch(row/2 + 2, col/2 -7, 'q' | A_BOLD);
    mvprintw(row/2 + 2, col/2 - 6, " for quit");
    
    getch();
}

void GUI::DisplayWon(){
    int row{}, col{};
    getmaxyx(stdscr, row, col);
    
    erase();
    
    mvprintw(row/2 - 2, col/2 - 11, "You won! Congratulations!");
    
    mvaddch(row/2, col/2 -7, 'r' | A_BOLD);
    mvprintw(row/2, col/2 - 6, " for restart");
    
    mvaddch(row/2 + 2, col/2 -7, 'q' | A_BOLD);
    mvprintw(row/2 + 2, col/2 - 6, " for quit");
    
    while(true){
        char pressed = getch();
        
        if(pressed == 'r'){
            fiveteens->Shuffle();
            break;
        }
        else if(pressed == 'q'){
            endwin();
            exit(0);
            break;
        }
    }
}
        
void GUI::DisplayFiveteens(){
    int row{}, col{};
    getmaxyx(stdscr, row, col);
    
    std::vector<short> fiveteensNums = fiveteens->GetFiveteens();
    
    erase();
    for(short i{0}; i < 16; i++){
    short currentRow = i / 4;
    short currentCol = i - 4*currentRow;
        
        DrawCell(row/2-6 + currentRow*3, col/2-13 + currentCol*7, fiveteensNums.at(i));
    }
    
    mvaddch(row-2, col/2 - 5, 'h' | A_BOLD);
    mvprintw(row-2, col/2 - 4, " for help");
}
        
//constructor
GUI::GUI(Fiveteens *fiveteensItem){
    fiveteens = fiveteensItem;
    
    initscr();
    raw();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
}

