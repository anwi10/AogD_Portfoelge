//
// Created by Anders on 10/5/2017.
//

#include "BallsAndBins.h"

BallsAndBins::BallsAndBins() {

}

BallsAndBins::~BallsAndBins() {

}

vector<int> BallsAndBins::ThrowBalls() {
    vector<int> ThrowBall;
    random_device rd;
    for (int i = 0; i < 32768; ++i) {
        int NewNumber = 0;
        NewNumber = rd() % 32768;
        ThrowBall.push_back(NewNumber);
    }
    return ThrowBall;
}

vector<int> BallsAndBins::SortListOfThrows(vector<int> &ListOfThrows) {

    sort(ListOfThrows.begin(), ListOfThrows.end());

    return ListOfThrows;
}

int BallsAndBins::HeighestAmountOfBalls(vector<int> &BinsWithBalls) {
    int HeighestAmountOfBallsSoFar = 0;
    int CurrentBallsInCurrentBin = 0;
    for (int i = 0; i < BinsWithBalls.size(); ++i) {

        CurrentBallsInCurrentBin++;
        if (BinsWithBalls[i] != BinsWithBalls[i + 1]) {
            if (CurrentBallsInCurrentBin > HeighestAmountOfBallsSoFar)
                HeighestAmountOfBallsSoFar = CurrentBallsInCurrentBin;
            CurrentBallsInCurrentBin = 0;
        }
    }


    return HeighestAmountOfBallsSoFar;
}

