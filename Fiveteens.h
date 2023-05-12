#ifndef Fiveteens_h
#define Fiveteens_h

#include <stdio.h>
#include <vector>

class Fiveteens{
    private:
        std::vector<short> fiveteens;
        short FindZero(std::vector<short> &fiveteens);
        void Fill();
    public:
        void MoveUp();
        void MoveRight();
        void MoveLeft();
        void MoveDown();
        void Shuffle();
        bool CheckWon();
        std::vector<short> GetFiveteens();
        Fiveteens();
};

#endif /* Fiveteens_hpp */
