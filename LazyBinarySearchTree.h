#pragma once
#include <string>
#include "TreeNode.h"

class LazyBinarySearchTree {
private:
	TreeNode* root;
	TreeNode* insert(TreeNode*, int, bool&);
	TreeNode* remove(TreeNode*, int, bool&);
	int findMin(TreeNode*);
	int findMax(TreeNode*);
	bool contains(TreeNode*,int);
	string print(TreeNode*);
	int height(TreeNode*);
	int size(TreeNode*);
	void clear(TreeNode*);

public:
	LazyBinarySearchTree();
	~LazyBinarySearchTree();

	void insert(ostream&, int);
	void remove(ostream&, int);
	void findMin(ostream&);
	void findMax(ostream&);
	void contains(ostream&, int);
	void print(ostream&);
	void height(ostream&);
	void size(ostream&);
};