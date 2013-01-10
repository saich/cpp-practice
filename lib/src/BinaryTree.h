#pragma once

struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int a, Node* l = NULL, Node* r = NULL)
		: value(a)
		, left(l)
		, right(r)
	{}
};