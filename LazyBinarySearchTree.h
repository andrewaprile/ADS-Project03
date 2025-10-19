#pragma once
#include <string>
#include "TreeNode.h"

class LazyBinarySearchTree {
private:
	TreeNode* root;
	TreeNode* insert(TreeNode*, int, bool&);
	TreeNode* remove(TreeNode*, int);
	int findMin(TreeNode*);
	int findMax(TreeNode*);
	bool contains(TreeNode*,int);
	string print(TreeNode*);
	int height(TreeNode*);
	int size(TreeNode*);

public:
	LazyBinarySearchTree();
	~LazyBinarySearchTree();

	bool insert(int);
	bool remove(int);
	int findMin();
	int findMax();
	bool contains(int);
	void print();
	int height();
	int size();
};