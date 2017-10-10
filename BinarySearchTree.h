#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

class BinaryNode
{
public:
    int Repetitions;
	int element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const int & theElement, int Rep, BinaryNode *lt, BinaryNode *rt)
		: element{ theElement }, left{ lt }, right{ rt } , Repetitions{ Rep } {}

	BinaryNode(int && theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
};


class BinarySearchTree
{
public:
	BinarySearchTree(); 
	BinarySearchTree(const BinarySearchTree & rhs); 
	BinarySearchTree(BinarySearchTree && rhs); 
	~BinarySearchTree();

	int NumberOfNodes();
	int NumberOfLEaves();
	int NumberOfFullNodes();
	int CountNumberOfNodes(BinaryNode * root);
	int CountNumberOfLeaves(BinaryNode * root);
	int CountNumberOFFullNodes(BinaryNode * root);
	int findMaxRepetition(BinaryNode *t, int Max);
	int findMaxRepetition();
	
	const int & findMin() const;
	const int & findMax() const;
	int contains(const int & x) const;
	bool isEmpty() const;
	void printTree() const;
    void PreOrder() const;
    void PostOrder() const;
    void LevelOrder() const;
    void PrintPath() const;

	
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);
	
private:
	BinaryNode *root;

	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;

	BinaryNode * StartRoot;
	int Counter = 0;
	
	int contains(const int & x, BinaryNode *t) const;
	
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;
    void PreOrder(BinaryNode *t) const;
    void PostOrder(BinaryNode *t) const;
    void LevelOrder(BinaryNode *t) const;
    int path(BinaryNode *t, int N) const;
	BinaryNode * clone(BinaryNode *t) const;



};

#endif
