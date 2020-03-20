// gcc include
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

#pragma once 

#define pow2(n) (1 << (n))

/*
	Implementation derived from https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
*/

typedef struct _avl
{
   int d;
   struct _avl *l;
   struct _avl *r;
} avl;

class avl_tree 
{
	private:
		avl* r;
	public:
		int height();
		int difference();
		avl* rr_rotate(avl*);
		avl* ll_rotate(avl*);
		avl* lr_rotate(avl*);
		avl* rl_rotate(avl*);
		avl* balance(avl*);
		avl* insert(avl*, int);
		void print(avl*, int);
		void inorder(avl*);
		void preorder(avl*);
		void postorder(avl*);
		avl_tree() {
			r = NULL;
		}
};
