#include <iostream>
#include "BallsAndBins.h"


int main() {
    BallsAndBins BandB;
    random_device rd;
    BinarySearchTree BinTree10;


    std::cout << "Balls and Bins test driver startet... " << std::endl;
    cout << "\nAssigment 1: " << endl;
    cout << "Throwing 10007 balls into 10007 bins, 1000 times... " << endl;
    for (int i = 0; i < 1000; ++i) {
        BinarySearchTree ThrowTree = BandB.ThrowBalls(10007);
        BinTree10.insert(BandB.HeighestAmountOfBalls(ThrowTree));
    }
    cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTree10.findMax() << endl;

    cout << "\nAssignment 3: " << endl;
    cout << "Throwing 32768 balls into 32768 bins, 1000 times... " << endl;

    BinarySearchTree BinTree32;
    for (int i = 0; i < 1000; ++i) {
        BinarySearchTree ThrowTree = BandB.ThrowBalls(32768);
        BinTree32.insert(BandB.HeighestAmountOfBalls(ThrowTree));
    }

    cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTree32.findMax()<< endl;
    cout << "We can with a very high certainty say, that if a bin can contain " << BinTree32.findMax() + 4 << " balls, the bin will never be full" << endl;



    cout << "\nAssignment 4.1: " << endl;
    cout << "Testing 'the power of two choices' on assignment 1: " << endl;

    BinarySearchTree BinTreePowerOFTwo;
    for (int i = 0; i < 1000; ++i) {
        BinarySearchTree ThrowTree = BandB.ThePowerOfTwoChoices(10007);
        BinTreePowerOFTwo.insert(BandB.HeighestAmountOfBalls(ThrowTree));
    }
    cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTreePowerOFTwo.findMax() << endl;

    cout << "\nAssignment 4.2: " << endl;
    cout << "Testing 'the power of two choices' on assignment 3: " << endl;

    BinarySearchTree BinTreePowerOFTwo32;
    for (int i = 0; i < 1000; ++i) {
        BinarySearchTree ThrowTree = BandB.ThePowerOfTwoChoices(32768);
        BinTreePowerOFTwo32.insert(BandB.HeighestAmountOfBalls(ThrowTree));
    }
    cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTreePowerOFTwo32.findMax() << endl;
    cout << "We can with a very high certainty say, that if a bin can contain " << BinTreePowerOFTwo32.findMax() + 4 << " balls, the bin will never be full" << endl;

    return 0;
}