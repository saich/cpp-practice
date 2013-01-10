// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"


Node* FindParent(Node* root, Node* searchee)
{
	Node* result(NULL);
	if(root == NULL)
		result = NULL;
	else if(root->left == searchee || root->right == searchee)
	{
		std::cout << root->value;
		result = root;
	}
	else
	{
		std::cout << root->value;
		// Check in left tree
		result =  FindParent(root->left, searchee);

		// Check in right tree
		if(!result)
			result = FindParent(root->right, searchee);
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node a(90);
	Node b(25);
	Node c(70);
	Node d(35, &b, &c);

	Node e(45, 0, &a);
	Node f(20, &e, 0);

	Node head(50, &f, &d);

	// Find parent of a node...

	Node* temp = FindParent(&head, &a);

	return 0;
}