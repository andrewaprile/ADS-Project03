# ADS-Project03

  

### Overview

This project is an assignment for UCO's Advanced Data Structures [CMSC 3613] course. The goal of this project was to implement a binary search tree with lazy deletion in C++. The two classes and their memebers are:  
  
  
**LazyBinarySearchTree**

variables:

*- root: TreeNode**

functions:  
*+ insert(key: int): bool**+ remove(key: int): bool + key: int**+ print(): string**+ size(): int**+ height(): int**+ findMin(): int**+ findMax(): int**+ constains(key: int): bool*

  

**TreeNode**

variables:

*+ key: int**+ right: TreeNode***+ deleted: bool**+ left: TreeNode**

The newer concept of the lazy binary search tree was finding the min and max nodes when some TreeNodes could be deleted. That is, the structure is still there, except a node could be simply marked as deleted instead of being recursively removed. This means when searching for the min or max, we need to make sure to bypass a deleted node while ensuring that a truly undeleted node is selected as a min or max. 

Let's say we are trying to find the **max** (min would simply be the opposite):

-   We need to search the right side of the binary tree, unless there is none, in which case the root node would be the maximum value stored in that tree.
-   If the right tree exists, and the right side traversal (normal path to max value if no Nodes are deleted) does not return a node (meaning all nodes in right subtrees are deleted), we must search the subsequent left subtrees.
-   Then we must traverse the tree in an In-Order manner as with normal binary tree: RVL for Max, LVR for Min

  

Here is the findMax function, notice how we go to the right-subtrees recursively first, then check the node, if a vaild value isn't found there, it will search the left-subtrees after.

![](blob:vscode-webview://1f0haj087p7h49n8h1suuald95pg7e4544pdvomcg9phbcim38vj/c81a4268-7dac-4f95-8bba-30d98b3de501) 

#### Code Execution

Using the makefile provided we can compile the program (please *make* sure **Make** is properly installed on your machine).

Also ensure that you are in a *bash* or linux based terminal when running these commands to avoid any complications. Or if you really want to use powershell for some reason, feel free to change the makefile commands to work best with your setup.

  

Here are the two commands needed to compile and run:  
  
this should compile the code (if error then likely in wrong directory or Make is not installed (properly or at all))  
`make`

  

and this should execute the code with the input.dat file as a parameter and naming the output file output.dat, which will store the data the program produces

`./p03 input.dat output.dat`

  

  

Here is the desired output so you can check that the code ran correctly.

----------------------------------------------------

![](blob:vscode-webview://1f0haj087p7h49n8h1suuald95pg7e4544pdvomcg9phbcim38vj/9529cee6-99b0-4d60-ab93-e08f19f2956f) 

----------------------------------------------------