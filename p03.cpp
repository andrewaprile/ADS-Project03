#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "LazyBinarySearchTree.h"

int main(int argc, char* argv[]){
	if (argc != 3) {
		cout << "Incorrect command line arguments." << endl; 
		return 0;
	}
	ofstream out;
	out.open(argv[2]);
	if (out.fail()) {
		cout << "Error: could not access output file." << endl;
		return 0;
	}
	ifstream inputFile(argv[1]);
	if (inputFile.fail()) {
		cout << "Error: could not access input file"<< endl;
		return 0;
	}
	

	LazyBinarySearchTree tree1;
	string line;
	while (getline(inputFile, line)){
		cout << line << endl;
		
		if (line.find(':') != string::npos) {
			int colonPosition = line.find(':');
			string command = line.substr(0, colonPosition);
			string argument = line.substr(colonPosition + 1);

			if(argument==""){
				// cout << "Error: " << command << " (no key)"<< endl;
				out << "Error: " << command << " (no key)"<< endl;
			}
			int key = stoi(argument);
			if(key<1 || key>99){
				// cout << "Error: " << command << " (illegal argument: not in range)" << endl;
				out << "Error: " << command << " (illegal argument: not in range)" << endl;
			} else if (command == "insert"){
				tree1.insert(out, key);
			} else if (command == "remove"){
				tree1.remove(out, key);
			} else if(command == "contains"){
				tree1.contains(out, key);
			}
		} else{ 
			if(line=="print"){
				tree1.print(out);
			} else if(line=="findMin"){
				tree1.findMin(out);
			} else if(line =="findMax"){
				tree1.findMax(out);
			} else if(line == "height"){
				tree1.height(out);
			} else if(line=="size"){
				tree1.size(out);
			} else if(line=="insert" || line=="remove" || line=="contains"){
				// cout << "Error: " << line << " (no key)"<< endl;
				out << "Error: " << line << " (no key)"<< endl;
			} else {
				// cout << "Error: " << line << " (invalid command)" << endl;
				out << "Error: " << line << " (invalid command)" << endl;
			}
		}
	}

	// //check that the valid set of keys are integers between 1 and 99
	// cout << boolalpha << tree1.insert(98) << endl;
	// cout << boolalpha << tree1.insert(67) << endl;
	// cout << boolalpha << tree1.insert(55) << endl;
	// cout << boolalpha << tree1.insert(45) << endl;
	// tree1.print();
	// cout << boolalpha << tree1.remove(84) << endl;
	// cout << boolalpha << tree1.remove(45) << endl;
	// cout << boolalpha << tree1.contains(45) << endl;
	// cout << tree1.findMin() << endl;
	// cout << tree1.findMax() << endl;
	// tree1.print();
	// cout << tree1.height() << endl;
	// cout << tree1.size() << endl;
	// cout << boolalpha << (tree1.insert(84)) << endl;
	// cout << boolalpha << (tree1.insert(32)) << endl;
	// cout << boolalpha << (tree1.insert(32)) << endl;
	// tree1.print();
	// cout << tree1.findMin() << endl;
	// cout << boolalpha << tree1.insert(980) << endl;
	// // tree1.insert();
	// // tree1.hiha();

	inputFile.close();
	out.close();
	return 0;
}