#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

Node* newNode(int key) {
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

void traverse(Node* root)
{
	if (root != NULL) {
		traverse(root->left);
		cout << root->key << " ";
		traverse(root->right);
	}
	else {
		root = newNode(0);
		cout << root->key << " ";
	}
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(5);
	root->right->right = newNode(4);

	traverse(root);

	return 0;
}
