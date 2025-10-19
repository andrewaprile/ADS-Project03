#pragma once

class TreeNode {
	private:
		int key;
		TreeNode* left;
		TreeNode* right;
		bool deleted;
	public:
		TreeNode(int);
		~TreeNode();

		friend class LazyBinarySearchTree;
};