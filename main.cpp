#include <iostream>
#include "BallsAndBins.h"


int main() {
    BallsAndBins BandB;
    random_device rd;
    BinarySearchTree BinTree10;
    int Entries;
    int Range;
    BinarySearchTree BinTree;
    BinarySearchTree BinTree32;
    BinarySearchTree BinTreePowerOFTwo;
    BinarySearchTree BinTreePowerOFTwo32;
    char Choose;

    cout << "Wanna test traversals, or Balls and bins?: a = Traversals , b = Balls and Bins" << endl;
    cin >> Choose;
    switch (Choose){
        case 'a' :

            cout << "Binary search tree test driver startet..." << endl;
            cout << "please enter the amount of entries in the search tree : " << endl;
            cin >> Entries;
            cout << "Enter the range of the numbers in the tree : " << endl;
            cin >> Range;

            cout << "Creating search tree... " << endl;
            for (int i = 0; i < Entries; ++i) {
                int var = rand() % Range;
                BinTree.insert(var);
            }
            cout << "Pre order traversal : " << endl;
            BinTree.PreOrder();
            cout << "\n";
            cout << "Post order traversal : " << endl;
            BinTree.PostOrder();
            cout << "\n";
            cout << "In order traversal : " << endl;
            BinTree.printTree();
            cout << "\n";
            cout << "Level order traversal :" << endl;
            BinTree.LevelOrder();
            cout << "\n";
            cout << "Number of nodes : " << BinTree.NumberOfNodes() << endl;
            cout << "Number of leaves : " << BinTree.NumberOfLEaves() << endl;
            cout << "Number of full nodes : " << BinTree.NumberOfFullNodes() << endl;
            cout << "The internal path lenght : ";
            BinTree.PrintPath();
            cout << "Binary search tree test driver stopped" << endl;
            break;
        case 'b' :
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
            for (int i = 0; i < 1000; ++i) {
                BinarySearchTree ThrowTree = BandB.ThrowBalls(32768);
                BinTree32.insert(BandB.HeighestAmountOfBalls(ThrowTree));
            }

            cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTree32.findMax()<< endl;
            cout << "We can with a very high certainty say, that if a bin can contain " << BinTree32.findMax() + 4 << " balls, the bin will never be full" << endl;



            cout << "\nAssignment 4.1: " << endl;
            cout << "Testing 'the power of two choices' on assignment 1: " << endl;
            for (int i = 0; i < 1000; ++i) {
                BinarySearchTree ThrowTree = BandB.ThePowerOfTwoChoices(10007);
                BinTreePowerOFTwo.insert(BandB.HeighestAmountOfBalls(ThrowTree));
            }
            cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTreePowerOFTwo.findMax() << endl;

            cout << "\nAssignment 4.2: " << endl;
            cout << "Testing 'the power of two choices' on assignment 3: " << endl;

            for (int i = 0; i < 1000; ++i) {
                BinarySearchTree ThrowTree = BandB.ThePowerOfTwoChoices(32768);
                BinTreePowerOFTwo32.insert(BandB.HeighestAmountOfBalls(ThrowTree));
            }
            cout << "Out of 1000 tries, the maximum number of balls in one bin was: " << BinTreePowerOFTwo32.findMax() << endl;
            cout << "We can with a very high certainty say, that if a bin can contain " << BinTreePowerOFTwo32.findMax() + 4 << " balls, the bin will never be full" << endl;

            break;
        default: break;
    }


    return 0;
}