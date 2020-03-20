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

int avl_tree::height(avl *t) 
{
	int h = 0;
	if (t != NULL) 
	{
		int l_height = height(t->l);
		int r_height = height(t->r);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

avl *avl_tree::balance(avl *t) 
{
	int bal_factor = difference(t);
	if (bal_factor > 1) 
	{
		if (difference(t->l) > 0)
			t = ll_rotate(t);
		else
			t = lr_rotate(t);
	} 
	else if (bal_factor < -1) 
	{
		if (difference(t->r) > 0)
			t = rl_rotate(t);
		else
			t = rr_rotate(t);
	}
	return t;
}
