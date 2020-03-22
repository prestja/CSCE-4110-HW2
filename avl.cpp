/*
	CSCE 4110 Homework 2
	Jacob Preston, Richard Butler, Justin Dupuis
	Spring 2020
*/

#include "avl.h"

/*
	Implementation derived from https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
*/

avl* avl_tree::getRoot() 
{
	return root;
}

avl* avl_tree::setRoot(avl* which) 
{
	root = which;
}

void avl_tree::preorder(avl* t) {
	if (t == NULL) 
	{
		return;
	}
	std::cout << t->d << " ";
	preorder(t->l);
	preorder(t->r);
}

int avl_tree::height(avl* t) 
{
	int h = 0;
	if (t != NULL) 
	{
		int l_height = height(t->l);
		int r_height = height(t->r);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int avl_tree::difference(avl* t) {
	int l_height = height(t->l);
	int r_height = height(t->r);
	int b_factor = l_height - r_height;
	return b_factor;
}

avl *avl_tree::balance(avl* t) 
{
	int bal_factor = difference(t);
	if (bal_factor > balanceFactor) 
	{
		if (difference(t->l) > 0)
			t = ll_rotate(t);
		else
			t = lr_rotate(t);
	} 
	else if (bal_factor < -balanceFactor) 
	{
		if (difference(t->r) > 0)
			t = rl_rotate(t);
		else
			t = rr_rotate(t);
	}
	return t;
}

avl* avl_tree::insert(avl* t, int v) 
{	
	if (t == NULL) 
	{
		t = new avl;
		t->d = v;
		t->l = NULL;
		t->r = NULL;		
		return t;
	} 
	else if (v < t->d) 
	{
		t->l = insert(t->l, v);
		t = balance(t);
	} 
	else if (v >= t->d) 
	{
		t->r = insert(t->r, v);
		t = balance(t);
	} 
	return t;
}

avl* avl_tree::rr_rotate(avl* parent) 
{
	avl *t;
	t = parent->r;
	parent->r = t->l;
	t->l = parent;
	std::cout<<"Right-Right Rotation\n";
	return t;
}

avl* avl_tree::ll_rotate(avl* parent) 
{
	avl *t;
	t = parent->l;
	parent->l = t->r;
	t->r = parent;
	std::cout<<"Left-Left Rotation\n";
	return t;
}

avl* avl_tree::lr_rotate(avl* parent) 
{
	avl *t;
	t = parent->l;
	parent->l = rr_rotate(t);
	std::cout<<"Left-Right Rotation\n";
	return ll_rotate(parent);
}

avl* avl_tree::rl_rotate(avl* parent) 
{
	avl *t;
	t = parent->r;
	parent->r = ll_rotate(t);
	std::cout<<"Right-Left Rotation\n";
	return rr_rotate(parent);
}

avl* avl_tree::findAnyLeaf(avl* t)
{	
	// returns the in-order traversal finding the furthest-down leaf node
	if (t->l != NULL) 
	{
		return findAnyLeaf(t->l);
	}
	if (t->r != NULL) 
	{
		return findAnyLeaf(t->r);
	}
	return t;
}
