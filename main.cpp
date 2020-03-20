/*
	CSCE 4110 Homework 2
	Jacob Preston, Richard Butler, Justin Dupuis
	Spring 2020
*/

// gcc include
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
// project include
#include "avl.h"

void parse(avl_tree* tree, char* path) 
{
	std::cout << "Consuming " << path << std::endl; 

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
	parse(tree, argv[1]);
	//tree->preorder(tree->getRoot());
	//std::cout << std::endl;
	
	avl* leaf = tree->findAnyLeaf(tree->getRoot());
	//std::cout << leaf->d << std::endl;
} 
