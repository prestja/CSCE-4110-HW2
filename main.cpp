/*
	CSCE 4110 Homework 2
	Jacob Preston, Richard Butler, Justin Dupuis
	Spring 2020
*/

// gcc include
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <stdio.h>
#include <unistd.h>
#include <vector>
// project include
#include "avl.h"

std::vector<int> buffer;


void parse(avl_tree* tree, char* path) 
{
	std::ifstream file (path);
	std::string line;
	int next;

	while (file >> next) 
	{
		buffer.push_back(next);
	}

	// inserts the first element so that root is never null
	avl* root = new avl();
	root->d = buffer[0];
	root->l = NULL;
	root->r = NULL;
	tree->setRoot(root);

	// inserts all remaining elements
	for (int i = 1; i < buffer.size(); i++) 
	{
		root=tree->insert(root, buffer[i]);
	}
}

int main (int argc, char** argv) 
{
	if (argc < 3) {
		std::cout << "Please run this program with two arguments\nExample usage: ./avl <inputPath> <balancefactor>\n";
	}
	int balFac = 1;
	balFac = std::stoi(argv[2]);
	// create a new tree
	avl_tree* tree = new avl_tree(balFac);

	// parse tree and insert all elements from input file
	auto i_start = std::chrono::steady_clock::now();
	parse(tree, argv[1]);
	auto i_end = std::chrono::steady_clock::now();
	std::cout << "Insertion: " << std::chrono::duration_cast<std::chrono::milliseconds>(i_end - i_start).count() << "ms" << std::endl;
	
	// find any leaf node to consider worst-case search time
	auto f_start = std::chrono::steady_clock::now();
	avl* leaf = tree->findAnyLeaf(tree->getRoot());
	auto f_end = std::chrono::steady_clock::now();
	std::cout << "Find: " << std::chrono::duration_cast<std::chrono::milliseconds>(f_end - f_start).count() << "ms" << std::endl;
	std::cout << std::endl;
	
} 
