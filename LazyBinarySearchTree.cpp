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
int LazyBinarySearchTree::height(){
	return height(root);
}
int LazyBinarySearchTree::height(TreeNode* node){
	if (node==nullptr){
		return -1;
	}
	else{
		int leftHeight = height(node->left);
		int rightHeight= height(node->right):
		if (leftHeight > rightHeight){
			return leftHeight + 1;
		}
		else{
			return rightHeight + 1;
		}
	}
	
}
int LazyBinarySearchTree::size(){
	return size(root);
}
int LazyBinarySearchTree::size(TreeNode* node){
	if (node==nullptr){
		return 0;
	}else{
		return size(node->left) + size(node->right);
	}
}

string LazyBinarySearchTree::print(){
	return print(root);
}
string LazyBinarySearchTree::print(TreeNode* node){
	if (node == nullptr){
		return "";
	}
	else{
		cout << node->key << " " << print(node->left) << " " << print(node->right);
	}
	return "";
}

