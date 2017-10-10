//
// Created by Anders on 10/5/2017.
//

#include "BallsAndBins.h"

BallsAndBins::BallsAndBins() {

}

BallsAndBins::~BallsAndBins() {

}

vector<int> BallsAndBins::ThrowBalls(int Throws) {
    vector<int> ThrowBall;
    random_device rd;
    for (int i = 0; i < Throws; ++i) {
        int NewNumber = 0;
        NewNumber = rd() % Throws;
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

vector<int> BallsAndBins::ThePowerOfTwoChoices(int Throws) {
    vector<int> ThrowBalls;
    random_device rd;

    for (int i = 0; i < Throws; ++i) {

        int A = 0;
        int B = 0;
        A = rd() % Throws;
        B = rd() % Throws;
        int CounterA = 0;
        int CounterB = 0;
        if (ThrowBalls.empty()){
            ThrowBalls.push_back(A);
        }
        else{
          for (int j = 0; j < ThrowBalls.size(); ++j) {

            if (ThrowBalls.at(j) == A){
               CounterA++;
            }
            else if(ThrowBalls.at(j) == B){
               CounterB++;
            }

          }
        if (CounterA == CounterB){
            ThrowBalls.push_back(A);
        }
        else if (CounterA > CounterB){
            ThrowBalls.push_back(B);
        }
        else {
            ThrowBalls.push_back(A);
        }
    }}
    return ThrowBalls;
}


