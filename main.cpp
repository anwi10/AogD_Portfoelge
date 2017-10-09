#include <iostream>
#include "BallsAndBins.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    BallsAndBins BandB;
    random_device rd;
    cout << "a random number : " << rd() % 32768 << endl;
    vector<int> HeghestAmountOfBallsInBins;


    for (int i = 0; i < 1000; ++i) {
        vector<int> testVector = BandB.ThrowBalls();
        testVector = BandB.SortListOfThrows(testVector);
        HeghestAmountOfBallsInBins.push_back(BandB.HeighestAmountOfBalls(testVector));
    }

    sort(HeghestAmountOfBallsInBins.begin(), HeghestAmountOfBallsInBins.end());
    cout << HeghestAmountOfBallsInBins[HeghestAmountOfBallsInBins.size() - 1] << endl;


    return 0;
}