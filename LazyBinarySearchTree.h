#pragma once
#include <string>
#include "TreeNode.h"

class LazyBinarySearchTree {
private:
	TreeNode* root;
	bool insert(TreeNode*, int);
	bool remove(TreeNode*, int);
	int findMin(TreeNode*);
	int findMax(TreeNode*);
	bool contains(int key);
	// string print();
	int height();
	int size();

public:
	LazyBinarySearchTree();
	~LazyBinarySearchTree();

	// Public interface methods
	void insert(int);
	void remove(int);
	int findMin();
	int findMax();
	// string print();
	int height();
	int size();
};