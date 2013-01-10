#include <iostream>
#include <vector>
#include <string>
#include <string.h>

typedef std::vector<std::string> sVec;

struct Node {
	int max_val;		// Highest value of the recipe
	size_t max_index;	// Index in the vector corresponding to the valuest recipe

	Node* children[27];
	Node()
		: max_val(0)
		, max_index(0)
		, children()
	{}
};

inline size_t char2index(char ch)
{
	return (ch == '-') ? 26 : ch - 'a';
}

void Insert(Node* root, char* recipe, int index, int value)
{
	int len = strlen(recipe);

	Node* curr = root;

	for(int i = 0; i < len; i++)
	{
		int idx = char2index(recipe[i]);
		if(!curr->children[idx])
		{
			curr->children[idx] = new Node();
			curr->children[idx]->max_index = index;
			curr->children[idx]->max_val = value;
		}
		else if(value > curr->children[idx]->max_val)
		{
			// Node is already there..
			curr->children[idx]->max_index = index;
			curr->children[idx]->max_val = value;
		}

		curr = curr->children[idx];
	}
}

Node* Find(Node* root, char* str)
{
	int len = strlen(str);
	Node* curr = root;
	
	for(int i = 0; i < len; i++)
	{
		int idx = char2index(str[i]);
		if(curr->children[idx])
			curr = curr->children[idx];
		else
			return NULL;
	}
	return curr;
}

int remember_the_recipe()
{
	int N, V;
	char recipe[1001];

	scanf("%d", &N);

	Node root;

	sVec recipes;
	recipes.reserve(N);

	for(int i = 0; i < N; i++)
	{
		scanf("%s", recipe);
		scanf("%d", &V);
		recipes.push_back(recipe);		// Insert the string into vector
		Insert(&root, recipe, i, V);	// Insert string + value into Trie
	}

	// Queries...

	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++)
	{
		scanf("%s", recipe);
		Node* sol = Find(&root, recipe);
		if(sol) {
			std::cout << recipes[sol->max_index] << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}


	// TODO: Cleanup all memory...

	return 0;
}