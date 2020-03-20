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
		std::cout << next << "\n";
	}
}

int main (int argc, char** argv) 
{
	if (argc < 2) {
		std::cout << "Please run this program with two arguments\nExample usage: ./avl <inputPath>\n";
	}
	avl_tree* avl = new avl_tree();
	parse(avl, argv[1]);
} 
