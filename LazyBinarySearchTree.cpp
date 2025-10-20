#include <iostream>
#include <string>
using namespace std;
#include "LazyBinarySearchTree.h"

LazyBinarySearchTree::LazyBinarySearchTree() : root(nullptr) {}
LazyBinarySearchTree::~LazyBinarySearchTree()
{
	clear(root);
	root = nullptr;
}
void LazyBinarySearchTree::clear(TreeNode *node)
{
	if (node != nullptr)
	{
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

void LazyBinarySearchTree::insert(ostream &out, int key)
{
	if (key < 1 || key > 99)
	{
		out << "Error: insert (illegal argument: not in range)" << endl;
	}
	bool inserted = false;
	root = insert(root, key, inserted);
	out << boolalpha << inserted << endl;
}
TreeNode *LazyBinarySearchTree::insert(TreeNode *node, int key, bool &inserted)
{

	if (node == nullptr)
	{
		inserted = true;
		return new TreeNode(key);
	}
	else if (key < node->key)
	{
		node->left = insert(node->left, key, inserted);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key, inserted);
	}
	else if (key == node->key && node->deleted == true)
	{
		node->deleted = false;
		inserted = true;
	}
	return node;
}

void LazyBinarySearchTree::remove(ostream &out, int key)
{
	bool removed = false;
	root = remove(root, key, removed);
	out << boolalpha << removed << endl;
}
TreeNode *LazyBinarySearchTree::remove(TreeNode *node, int key, bool &removed)
{
	if (node == nullptr)
	{
		removed = false;
		return nullptr;
	}
	else if (key < node->key)
	{
		node->left = remove(node->left, key, removed);
	}
	else if (key > node->key)
	{
		node->right = remove(node->right, key, removed);
	}
	else if (key == node->key)
	{
		node->deleted = true;
		removed = true;
	}
	return node;
}

void LazyBinarySearchTree::findMin(ostream &out)
{
	out << findMin(root) << endl;
}
int LazyBinarySearchTree::findMin(TreeNode *node)
{
	if (node == nullptr)
	{
		return -1;
	}

	int leftMin = findMin(node->left);

	if (leftMin != -1)
	{
		return leftMin;
	}

	if (node->deleted == false)
	{
		return node->key;
	}

	return findMin(node->right);
}

void LazyBinarySearchTree::findMax(ostream &out)
{
	out << findMax(root) << endl;
}
int LazyBinarySearchTree::findMax(TreeNode *node)
{
	if (node == nullptr)
	{
		return -1;
	}

	// right search
	int rightMax = findMax(node->right);

	if (rightMax != -1)
	{
		return rightMax;
	}

	// true case : where we find true max
	if (!node->deleted)
	{
		return node->key;
	}

	// left search
	return findMax(node->left);
}

void LazyBinarySearchTree::contains(ostream &out, int key)
{
	out << boolalpha << contains(root, key) << endl;
}
bool LazyBinarySearchTree::contains(TreeNode *node, int key)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->key == key && node->deleted == false)
	{
		return true;
	}
	return contains(node->left, key) || contains(node->right, key);
}

void LazyBinarySearchTree::print(ostream &out)
{
	out << print(root) << endl;
}
string LazyBinarySearchTree::print(TreeNode *node)
{
	if (node == nullptr)
	{
		return "";
	}
	else
	{
		if (node->deleted == true)
		{
			return "*" + to_string(node->key) + " " + print(node->left) + " " + print(node->right);
		}
		else
		{
			return to_string(node->key) + " " + print(node->left) + " " + print(node->right);
		}
	}
}

void LazyBinarySearchTree::height(ostream &out)
{
	out << height(root) << endl;
}
int LazyBinarySearchTree::height(TreeNode *node)
{
	if (node == nullptr)
	{
		return -1;
	}
	else
	{
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);
		if (leftHeight > rightHeight)
		{
			return leftHeight + 1;
		}
		else
		{
			return rightHeight + 1;
		}
	}
}

void LazyBinarySearchTree::size(ostream &out)
{
	out << size(root) << endl;
}
int LazyBinarySearchTree::size(TreeNode *node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return size(node->left) + size(node->right) + 1;
	}
}