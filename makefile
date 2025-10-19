LazyBinarySearchTree: TreeNode.o LazyBinarySearchTree.o p03.o
	g++ -o LazyBinarySearchTree TreeNode.o LazyBinarySearchTree.o p03.o

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -c TreeNode.cpp

LazyBinarySearchTree.o: LazyBinarySearchTree.h LazyBinarySearchTree.cpp TreeNode.h
	g++ -c LazyBinarySearchTree.cpp

p03.o: p03.cpp LazyBinarySearchTree.h
	g++ -c p03.cpp

clean:
	rm *.o *.exe