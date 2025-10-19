#include <iostream>
#include <fstream>
using namespace std;
#include "LazyBinarySearchTree.h"

int main(){
	/*int argc, char* argv[]*/
	// if (argc != 3) {cout << "Incorrect command line arguments." << endl; return EXIT_FAILURE;}
	// string inputfile = argv[1];
	// string outputfile = argv[2];
	// cout << "Input file: " << inputfile << endl;
	// cout << "Output file: " << outputfile << endl;

	// ofstream output;
	// output.open(argv[2]);
	// if (output.fail()) {cout << "Could not access output file." << endl; return EXIT_FAILURE;}
	cout << "hello"<< endl;
	LazyBinarySearchTree tree1;
	tree1.insert(98);
	// tree1.insert(67);
	// tree1.insert(55);
	// tree1.insert(45);
	// tree1.insert(45);

	// tree1.print();
	// cout << tree1.size();

	cout << "here"<< endl;
	/*
		insert:98
		insert:67
		insert:55
		insert:45
		print 
		remove:84
		remove:45
		contains:45
		findMin
		findMax
		print
		height
		size
		insert:84
		insert:32
		insert:32
		print
		findMin
		insert:980
		insert
		hiha
	*/
	cout << "done"<< endl;
	return 0;
	cout << "program done"<< endl;
}