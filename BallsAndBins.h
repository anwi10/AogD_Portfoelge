//
// Created by Anders on 10/5/2017.
//

#ifndef BALLSANDBINS_BALLSANDBINS_H
#define BALLSANDBINS_BALLSANDBINS_H

#include <iostream>
#include "vector"
#include <algorithm>
#include <random>
#include "BinarySearchTree.h"

using namespace std;

class BallsAndBins {

public:

    BallsAndBins();

    ~BallsAndBins();

    int HeighestAmountOfBalls(BinarySearchTree &);

    vector<int> SortListOfThrows(vector<int> &);

    BinarySearchTree ThrowBalls(int);

    BinarySearchTree ThePowerOfTwoChoices(int);

private:


};


#endif //BALLSANDBINS_BALLSANDBINS_H
