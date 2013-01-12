// Practice.cpp : Defines the entry point for the console application.
//

#include <cstddef> // for NULL
#include <iostream>
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
