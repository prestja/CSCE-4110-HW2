#include "RBtree.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc < 2) 
	{
		std::cout << "Error! Run this program with at least one command line argument" << std::endl;
	}
	//Input sizes are 10,000, 100,000, and 1,000,000

	//Experiment 1

	//Creating RB tree
	RBTree tree;

	//open text file compiled with correct number of ints beforehand
	ifstream inputfile;
	inputfile.open(argv[1]);
	//start timer
	auto start= std::chrono::steady_clock::now();

	// for loop inserts each number from .txt file into tree using tree's function
	    //Done for 3 different random orderings
	    //And 1 with shuffling commented out 

	int next;
	while (inputfile >> next)
	{
	    tree.insert(next);
	}

	//End timer and cout time for insertion operations
	auto end =std::chrono::steady_clock::now();

	//commented out std::chrono::duration<float> duration=end-start;
	auto duration= std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

	std::cout <<"time for insertion is " << duration.count() << " ms" << "\n";

	//Closing file stream
	inputfile.close();
	//Start timer
	auto startsort = std::chrono::steady_clock::now();
	//Run search for example int 67 on 3 different random orderings
	tree.searchTree(67);
	//end timer and cout time for search operation
	auto endsort = std::chrono::steady_clock::now();

	auto sortduration= std::chrono::duration_cast<std::chrono::milliseconds>(endsort-startsort);
	std::cout <<"time for searching is " << sortduration.count() << " ms" << "\n";
}
