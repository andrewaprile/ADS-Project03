#include <iostream>
using namespace std;
#include "LazyBinarySearchTree.h"

LazyBinarySearchTree::LazyBinarySearchTree() : root(nullptr) {}

LazyBinarySearchTree::~LazyBinarySearchTree() {
	while (root != nullptr){
		remove(root->key);	
	}
}

int LazyBinarySearchTree::findMin() {
	return findMin(root);
}

int LazyBinarySearchTree::findMin(TreeNode* node){
	if (node == nullptr){
		return -1;
	}
	if (node->left == nullptr){
		return node->key;
	} else {
		return findMin(node->left);
	}
}
int LazyBinarySearchTree::findMax(){
	return findMax(root);
}
int LazyBinarySearchTree::findMax(TreeNode* node){
	if (node == nullptr){
		return -1;
	}
	if (node->right == nullptr){
		return node->key;
	} else {
		return findMax(node->right);
	}
}

