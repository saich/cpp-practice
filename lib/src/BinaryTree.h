#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(int a, Node* l = NULL, Node* r = NULL)
		: value(a)
		, left(l)
		, right(r)
	{}
};

#endif
