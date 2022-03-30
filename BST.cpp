#include<iostream>
#include<vector>

using namespace std;

class Node {

	int data;
	Node *right, *left;

public:

	Node();
	Node(int);

	//insert new node
	Node* Insert(Node*, int);

	//inorder view
	void Inorder(Node*);
	//postorder view
	void Postorder(Node*);
	//preorder view
	void Preorder(Node*);

	//find element
	void FindNode(Node*, int);
};

//define default construct
Node::Node():
	data(0),
	right(NULL),
	left(NULL)
{}

// Parameterized Constructor definition.
Node ::Node(int value)
{
	data = value;
	left = right = NULL;
}

//Find element address
void Node:: FindNode(Node* root, int value)
{

	if (!root)
	{	cout << "it doesn't exist" << endl;
		return;
	}
	if (root->data < value)
		FindNode(root->right, value);
	else if (root->data > value)
		FindNode(root->left, value);
	else if (root->data == value)
		cout << "it exist" << endl;
}
// Insert function definition.
Node* Node ::Insert(Node* root, int value)
{
	if (!root) {
		// Insert the first node, if root is NULL.
		return new Node(value);
	}

	//if value is bigger that root's value
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}

	//if value is smaller than root's value
	else
	{
		root->left = Insert(root->left, value);
	}

	return root;
}

//show tree values inorder
void Node::Inorder(Node* node)
{
	if (!node)
	{
		return;
	}
	Inorder(node->left);
	cout << node->data << endl;
	Inorder(node->right);
}
//show tree values postorder
void Node::Postorder(Node* node)
{
	if (!node)
	{
		return;
	}
	Postorder(node->left);
	Postorder(node->right);
	cout << node->data << endl;
}

//show tree values postorder
void Node::Preorder(Node* node)
{
	if (!node)
		return;
	cout << node->data << endl;
	Preorder(node->left);
	Preorder(node->right);
}

int main()
{
	Node node, *root = NULL;
	root = node.Insert(root, 1);
	node.Insert(root, 2);
	node.Insert(root, 4);
	node.Insert(root, 3);
	node.Insert(root, 5);
	node.Insert(root,10);

	node.FindNode(root, 5);
	node.FindNode(root, 10);
	node.Inorder(root);

	return 0;
}

