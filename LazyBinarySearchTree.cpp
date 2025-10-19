#include <iostream>
#include <string>
using namespace std;
#include "LazyBinarySearchTree.h"

LazyBinarySearchTree::LazyBinarySearchTree() : root(nullptr) {}
LazyBinarySearchTree::~LazyBinarySearchTree() {
	while (root != nullptr){
		// remove(root->key);	
	}
}
bool LazyBinarySearchTree::insert(int key){
	bool inserted = false;
	root = insert(root, key, inserted);
	return inserted;
}
TreeNode* LazyBinarySearchTree::insert(TreeNode* node, int key, bool& inserted){
	if(node==nullptr){
		inserted = true;
		return new TreeNode(key);
	} else if(key < node->key){
		node->left = insert(node->left, key, inserted);
	} else if(key > node->key){
		node->right = insert(node->right, key, inserted);
	} else if(key == node->key && node->deleted == true){
		node->deleted = false;
		inserted = true;
	}
	return node;
}

// // bool LazyBinarySearchTree::remove(int key){

// // }
// // TreeNode* LazyBinarySearchTree::remove(TreeNode* node, int key){

// }

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
	if (node == nullptr || node->deleted == true){
		return -1;
	}
	if (node->right == nullptr){
		return node->key;
	} else {
		return findMax(node->right);
	}
}

bool LazyBinarySearchTree::contains(int key){
	return contains(root, key);

}
bool LazyBinarySearchTree::contains(TreeNode* node, int key){
	if (node==nullptr){
		return false;
	}
	if(node->key == key && node->deleted == false){
		return true;
	}
	return contains(node->left, key) || contains(node->right, key);
}

void LazyBinarySearchTree::print(){
	cout << print(root) << "\n";
}
string LazyBinarySearchTree::print(TreeNode* node){
	if (node == nullptr){
		return "nullptr";
	}
	else{
		return to_string(node->key) + " " + print(node->left) + " " + print(node->right);
	}
	cout << "print end"<< endl;
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
		int rightHeight= height(node->right);
		if (leftHeight > rightHeight){
			return leftHeight + 1;
		} else{
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
		return size(node->left) + size(node->right) + 1;
	}
	cout << "size end"<< endl;
}