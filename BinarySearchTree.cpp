#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

int BinarySearchTree::contains(const int & x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

void BinarySearchTree::PreOrder() const {
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        PreOrder(root);
}

void BinarySearchTree::PostOrder() const {
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        PostOrder(root);
}

void BinarySearchTree::LevelOrder() const {
    if (isEmpty())
        cout << "Empty tree" << endl;
    else
        LevelOrder(root);
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
	remove(x, root);
}

void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, 1, nullptr, nullptr };
    else if(t->element == x)
        t->Repetitions++;
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

int  BinarySearchTree::findMaxRepetition(BinaryNode *t, int Max)
{
	BinaryNode Root = *t;
	if (t != nullptr)
	{
		while(t->right != nullptr) {
			if(t->Repetitions > Max)
				Max = t->Repetitions;
			t = t->right;
		}
		t = &Root;
		while(t->left != nullptr) {
			if (t->Repetitions > Max)
				Max = t->Repetitions;
			t = t->left;
		}

	}
	return Max;
}
int  BinarySearchTree::findMaxRepetition()
{
	return findMaxRepetition(root,0);
}

int BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
	if (t == nullptr)
		return 0;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return t->Repetitions;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode *t) const
{
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << " ";
		printTree(t->right);
	}
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element,t->Repetitions, clone(t->left), clone(t->right) };
}

int BinarySearchTree::CountNumberOfNodes(BinaryNode *root) {
	if(root == nullptr){
		return 0;
	}
	else{
		return 1 + CountNumberOfNodes(root->right) + CountNumberOfNodes((root->left));
	}
}

int BinarySearchTree::CountNumberOfLeaves(BinaryNode *root) {
	if(root == nullptr){
		return 0;
	}
	else if(root->left == nullptr && root->right == nullptr){
		return 1;
	}
	else{
		return CountNumberOfLeaves(root->left) + CountNumberOfLeaves(root->right);
	}
}

int BinarySearchTree::CountNumberOFFullNodes(BinaryNode *root) {
	if(root == nullptr){
		return 0;
	}
    else if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    else{
        return CountNumberOfLeaves(root->left) + CountNumberOfLeaves(root->right) - 1;
    }
}

int BinarySearchTree::NumberOfNodes() {
	return CountNumberOfNodes(root);
}

int BinarySearchTree::NumberOfLEaves() {
	return CountNumberOfLeaves(root);
}

int BinarySearchTree::NumberOfFullNodes() {
	return CountNumberOFFullNodes(root);
}

void BinarySearchTree::PreOrder(BinaryNode *t) const {
    if (t != nullptr)
    {
        cout << t->element << " ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void BinarySearchTree::PostOrder(BinaryNode *t) const {
    if (t != nullptr)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->element << " ";
    }
}

void BinarySearchTree::LevelOrder(BinaryNode *t) const  {


    if (t != nullptr) {
       queue<BinaryNode*> levelOrder;
       levelOrder.push(t);
        while(!levelOrder.empty()){
            BinaryNode* current = levelOrder.front();
            cout << current->element << " ";
            if(current->left != nullptr){
                levelOrder.push(current->left);
            }
            if(current->right != nullptr){
                levelOrder.push(current->right);
            }
            levelOrder.pop();
        }
    }
}

int BinarySearchTree::path(BinaryNode *t, int N) const
{
    if (t != nullptr)
    {
        return path(t->left, N + 1) + path(t->right, N + 1) + N;
    }

    else
    {
        return 0;
    }
}

void BinarySearchTree::PrintPath() const {

    cout << path(root, 0) << endl;

}


