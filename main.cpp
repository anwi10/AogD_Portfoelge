#include <iostream>
#include "BallsAndBins.h"


int main() {
    BallsAndBins BandB;
    random_device rd;
    vector<int> HeghestAmountOfBallsInBins;
    std::cout << "Balls and Bins test driver startet... " << std::endl;
    cout << "\nAssigment 1: " << endl;
    cout << "Throwing 10007 balls into 10007 bins, 1000 times... " << endl;
    for (int i = 0; i < 1000; ++i) {
        vector<int> testVector = BandB.ThrowBalls(10007);
        testVector = BandB.SortListOfThrows(testVector);
        HeghestAmountOfBallsInBins.push_back(BandB.HeighestAmountOfBalls(testVector));
    }
    sort(HeghestAmountOfBallsInBins.begin(), HeghestAmountOfBallsInBins.end());
    cout << "Out of 1000 tryes, the maximum number of balls in one bin was: " << HeghestAmountOfBallsInBins[HeghestAmountOfBallsInBins.size() - 1] << endl;

    cout << "\nAssignment 3: " << endl;
    cout << "Throwing 32768 balls into 32768 bins, 1000 times... " << endl;
    for (int i = 0; i < 1000; ++i) {
        vector<int> testVector = BandB.ThrowBalls(32768);
        testVector = BandB.SortListOfThrows(testVector);
        HeghestAmountOfBallsInBins[i] = BandB.HeighestAmountOfBalls(testVector);
    }

    sort(HeghestAmountOfBallsInBins.begin(), HeghestAmountOfBallsInBins.end());
    cout << "Out of 1000 tryes, the maximum number of balls in one bin was: " << HeghestAmountOfBallsInBins[HeghestAmountOfBallsInBins.size() - 1] << endl;
    cout << "We can with a very high certainty say, that if a bin can contain " << HeghestAmountOfBallsInBins[HeghestAmountOfBallsInBins.size() - 1] + 4 << " balls, the bin will never be full" << endl;

    return 0;
}