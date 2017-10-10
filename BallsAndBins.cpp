//
// Created by Anders on 10/5/2017.
//

#include "BallsAndBins.h"

BallsAndBins::BallsAndBins() {

}

BallsAndBins::~BallsAndBins() {

}

BinarySearchTree BallsAndBins::ThrowBalls(int Throws) {
    BinarySearchTree ThrowBall;
    random_device rd;
    for (int i = 0; i < Throws; ++i) {
        int NewNumber = 0;
        NewNumber = rd() % Throws;
        ThrowBall.insert(NewNumber);
    }
    return ThrowBall;
}

vector<int> BallsAndBins::SortListOfThrows(vector<int> &ListOfThrows) {

    sort(ListOfThrows.begin(), ListOfThrows.end());
    return ListOfThrows;
}

int BallsAndBins::HeighestAmountOfBalls(BinarySearchTree &BinsWithBalls) {
    return BinsWithBalls.findMaxRepetition();
}

BinarySearchTree BallsAndBins::ThePowerOfTwoChoices(int Throws) {
    BinarySearchTree ThrowBalls;
    random_device rd;

    for (int i = 0; i < Throws; ++i) {

        int A = 0;
        int B = 0;
        A = rd() % Throws;
        B = rd() % Throws;
        if (ThrowBalls.isEmpty()){
            ThrowBalls.insert(A);
        }
        else{
        if (ThrowBalls.contains(A) == ThrowBalls.contains(B)){
            ThrowBalls.insert(A);
        }
        else if (ThrowBalls.contains(A) > ThrowBalls.contains(B)){
            ThrowBalls.insert(B);
        }
        else {
            ThrowBalls.insert(A);
        }
    }}
    return ThrowBalls;
}


