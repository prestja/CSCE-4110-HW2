/*
	CSCE 4110 Homework 2
	Jacob Preston, Richard Butler, Justin Dupuis
	Spring 2020
*/

// gcc include
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdio.h>
#include <unistd.h>
// project include
#include "avl.h"

void parse(avl_tree* tree, char* path) 
{
	std::ifstream file (path);
	std::string line;
	while (getline(file, line)) 
	{
		std::stringstream ss (line);
		int next;
		ss >> next;
		//std::cout << "Inserting " << next << std::endl;
		avl* root = tree->getRoot();
		avl* inserted = tree->insert(root, next);

		root = tree->getRoot();
		if (root == NULL) {
			tree->setRoot(inserted);
		}
	}
}

int main (int argc, char** argv) 
{
	if (argc < 2) {
		std::cout << "Please run this program with two arguments\nExample usage: ./avl <inputPath>\n";
	}

	// create a new tree and parse from the given input file, then perform a preorder traversal
	avl_tree* tree = new avl_tree();

	// parse tree and insert all elements from input file
	auto i_start = std::chrono::steady_clock::now();
	parse(tree, argv[1]);
	auto i_end = std::chrono::steady_clock::now();
	std::cout << "Insertion: " << std::chrono::duration_cast<std::chrono::nanoseconds>(i_end - i_start).count() << "ns" << std::endl;

	// find any leaf node to consider worst-case search time
	auto f_start = std::chrono::steady_clock::now();
	avl* leaf = tree->findAnyLeaf(tree->getRoot());
	auto f_end = std::chrono::steady_clock::now();
	std::cout << "Find: " << std::chrono::duration_cast<std::chrono::nanoseconds>(f_end - f_start).count() << "ns" << std::endl;
	std::cout << std::endl;
} 
