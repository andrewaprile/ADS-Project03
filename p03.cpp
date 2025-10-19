#include <iostream>
#include <fstream>
using namespace std;
// #include "LazyBinarySearchTree.h"

int main(int argc, char* argv[]){
	if (argc != 3) {cout << "Incorrect command line arguments." << endl; return EXIT_FAILURE;}
	string inputfile = argv[1];
	string outputfile = argv[2];
	cout << "Input file: " << inputfile << endl;
	cout << "Output file: " << outputfile << endl;

	ofstream output;
	output.open(argv[2]);
	if (output.fail()) {cout << "Could not access output file." << endl; return EXIT_FAILURE;}

}