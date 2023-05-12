#include "Fiveteens.h"


short Fiveteens::FindZero(std::vector<short> &fiveteens){
    short zeroPosition {};
    for(short i {0}; i < 16; i++){
        if (fiveteens.at(i) == 0)
            zeroPosition = i;
    }
    return zeroPosition;
}

void Fiveteens::Fill(){
    for(short i{0}; i < 16; i++)
        fiveteens.at(i) = i;
}

void Fiveteens::MoveDown(){
    short zeroPosition {FindZero(fiveteens)};
    if(zeroPosition > 3)
        std::swap(fiveteens.at(zeroPosition), fiveteens.at(zeroPosition - 4));
}

void Fiveteens::MoveUp(){
    short zeroPosition {FindZero(fiveteens)};
    if(zeroPosition < 12)
        std::swap(fiveteens.at(zeroPosition), fiveteens.at(zeroPosition + 4));
}

void Fiveteens::MoveLeft(){
    short zeroPosition {FindZero(fiveteens)};
        if((zeroPosition+1) %4 != 0)
            std::swap(fiveteens.at(zeroPosition), fiveteens.at(zeroPosition+1));
    }

void Fiveteens::MoveRight(){
    short zeroPosition {FindZero(fiveteens)};
    if(zeroPosition %4 != 0 )
        std::swap(fiveteens.at(zeroPosition), fiveteens.at(zeroPosition-1));
}

void Fiveteens::Shuffle(){
    srand((int)time(0));

    for(short i{0}; i < 16; i++){
        short randIndex = rand() % 15 +1;
        
    std::swap(fiveteens.at(i), fiveteens.at(randIndex));
    }
}

bool Fiveteens::CheckWon(){
    if(fiveteens.at(0) == 0){
        for(short i{1}; i < 15; i++){
            if(fiveteens.at(i) > fiveteens.at(i+1))
                return false;
        }
        return true;
    }
    else if(fiveteens.at(15) == 0)
    {
        for(short i{0}; i < 14; i++){
            if(fiveteens.at(i) > fiveteens.at(i+1))
                return false;
        }
        return true;;
    }
    
    return false;
}
        
std::vector<short> Fiveteens::GetFiveteens(){
        return fiveteens;
}
    
//constructor
Fiveteens::Fiveteens(){
    fiveteens.resize(16);
    Fill();
    Shuffle();
}
