#include "avl.h"

/*
	Implementation derived from https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree
*/

avl* avl_tree::getRoot() 
{
	return root;
}

avl* avl_tree::insert(avl *r, int v) 
{
	if (r == NULL) 
	{
		r = new avl;
		r->d = v;
		r->l = NULL;
		r->r = NULL;
		return r;
	} 
	else if (v < r->d) 
	{
		r->l = insert(r->l, v);
		r = balance(r);
	} 
	else if (v >= r->d) 
	{
		r->r = insert(r->r, v);
		r = balance(r);
	} 
	return r;
}
