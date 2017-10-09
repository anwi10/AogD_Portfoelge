//
// Created by Anders on 10/5/2017.
//

#ifndef BALLSANDBINS_BALLSANDBINS_H
#define BALLSANDBINS_BALLSANDBINS_H

#include <iostream>
#include "vector"
#include <algorithm>
#include <random>

using namespace std;

class BallsAndBins {

public:

    BallsAndBins();

    ~BallsAndBins();

    int HeighestAmountOfBalls(vector<int> &);

    vector<int> SortListOfThrows(vector<int> &);

    vector<int> ThrowBalls();

private:


};


#endif //BALLSANDBINS_BALLSANDBINS_H
