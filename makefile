p03.exe: TreeNode.o LazyBinarySearchTree.o p03.o
	g++ -o p03 TreeNode.o LazyBinarySearchTree.o p03.o

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -c TreeNode.cpp

LazyBinarySearchTree.o: LazyBinarySearchTree.h LazyBinarySearchTree.cpp TreeNode.h
	g++ -c LazyBinarySearchTree.cpp

p03.o: p03.cpp LazyBinarySearchTree.h
	g++ -c p03.cpp

clean:
	rm -f *.o *.exe *output.dat