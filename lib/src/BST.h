#include <utility>

template<typename T>
class BST {
public:
	BST(): root_(NULL), size_(0) {}
	bool empty() const {return !root_;}
	size_t size() const {return size_; }

private:
	class Node {
	public:
		T key;
		Node* left;
		Node* right;

		Node(int v = 0, Node* l = NULL, Node* r = NULL)
			: key(v), left(l), right(r) {}
	};

	size_t size_;
	Node* root_;

	typedef std::pair<Node*, Node*> NodePair;

	Node* min_(Node* root) const;
	Node* max_(Node* root) const;
	void insert_(Node* newnode);
	NodePair find_(const T& val) const; // Returns pair of the node and its parent..
	Node* erase_(const T& val); // Returns the node that is erased...

	void transplant_(Node* u, Node* v, Node* u_parent); // utility for erase function...

	Node* successor_(Node* node) const;
	Node* predecessor_(Node* node) const;

	template<class Function> void inorder_(Node* root, Function f) const;
	template<class Function> void preorder_(Node* root, Function f) const;
	template<class Function> void postorder_(Node* root, Function f) const;
};

template<typename T>
typename BST<T>::Node* BST<T>::min_(typename BST<T>::Node* root) const
{
	typedef typename BST<T>::Node Node;
	Node* temp = root;
	if(temp) {
		while(temp->left)
			temp = temp->left;
	}
	return temp;
}


template<typename T>
typename BST<T>::Node* BST<T>::max_(typename BST<T>::Node* root) const
{
	typedef typename BST<T>::Node Node;
	Node* temp = root;
	if(temp) {
		while(temp->right)
			temp = temp->right;
	}
	return temp;
}

template<typename T>
typename BST<T>::NodePair BST<T>::find_(const T& val) const 
{
	typedef typename BST<T>::Node Node;
	if(!root_) return std::make_pair(root_, nullptr); // empty tree..

	Node *parent(NULL), *visitor(root_);

	while(visitor && visitor->key != val)
	{
		parent = visitor;
		visitor = (val < visitor->key) ? visitor->left : visitor->right;
	}
	return std::make_pair(visitor, parent);
}

template<typename T>
void BST<T>::insert_(Node* newnode)
{
	++size_;
	if(root_ == NULL)
	{
		root_ = newnode;
		return;
	}

	Node *parent(NULL), *visitor(root_);
	while(visitor)
	{
		parent = visitor;
		visitor = (newnode->key < visitor->key) ? visitor->left : visitor->right;
	}

	if(newnode->key < parent->key)
		parent->left = newnode;
	else
		parent->right = newnode;
}

template<typename T>
void BST<T>::transplant_(typename BST<T>::Node* u, typename BST<T>::Node* v, typename BST<T>::Node* u_parent)
{
	if(!u_parent) //i.e; u is root
		root_ = v;
	else if(u_parent->left == u)
		u_parent->left = v;
	else if(u_parent->right == u)
		u_parent->right = v;
}

template<typename T>
typename BST<T>::Node* BST<T>::erase_(const T& val)
{
	NodePair pair = find_(val);
	if(!pair.first)
		return NULL; // val doesn't exist in the tree..

	--size_;

	Node* z = pair.first; // Node to be deleted...
	Node* p = pair.second; // parent of the node to be deleted...
	if(!z->left) 
		transplant_(z, z->right, p);
	else if(!z->right) 
		transplant_(z, z->left, p);
	else
	{
		// Find successor in the right subtree..
		Node* succ_parent(z), *successor(z->right);
		while(successor->left)
		{
			succ_parent = successor;
			successor = successor->left;
		}

		if(succ_parent != z)
		{
			succ_parent->left = successor->right;
			successor->right = z->right;
		}
		successor->left = z->left;
		transplant_(z, successor, p);
	}
	return z;
}

template<typename T>
typename BST<T>::Node* BST<T>::successor_(typename BST<T>::Node* node) const
{
	if(node->right)
		return min_(node->right);

	// start from root..
	Node* start = root_, *succ = NULL;
	while(start)
	{
		if(node == start)
			break;
		else if(node->key < start->key)
		{
			succ = start; // the parent in the "last left" from root to the node is the successor..
			start = start->left;
		}
		else
			start = start->right;
	}
	return succ;
}

template<typename T>
typename BST<T>::Node* BST<T>::predecessor_(typename BST<T>::Node* node) const
{
	if(node->left)
		return max_(node->right);

	// start from root..
	Node* start = root_, *pred = NULL;
	while(start)
	{
		if(node == start)
			break;
		else if(node->key < start->key)
			start = start->left;
		else
		{
			pred = start; // the parent in the "last right" from root to the node is the predecessor..
			start = start->right;
		}
	}
	return pred;
}

template<typename T>
template<class Function> void BST<T>::inorder_(Node* root, Function f) const
{
	if(root->left) inorder_(root->left, f);
	f(root->key);
	if(root->right) inorder_(root->right, f);
}

template<typename T>
template<class Function>
void BST<T>::preorder_(Node* root, Function f) const
{
	f(root->key);
	if(root->left) inorder_(root->left, f);
	if(root->right) inorder_(root->right, f);
}

template<typename T>
template<class Function>
void BST<T>::postorder_(Node* root, Function f) const
{
	if(root->left) inorder_(root->left, f);
	if(root->right) inorder_(root->right, f);
	f(root->key);
}
