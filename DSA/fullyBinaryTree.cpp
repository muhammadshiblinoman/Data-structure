#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

Node *insertFullBinaryTree(Node *&root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (root->left == NULL) {
        root->left = createNode(data);
    } 
    else if (root->right == NULL) {
        root->right = createNode(data);
    } 
    else {
        if (height(root->left) <= height(root->right)) {
            root->left = insertFullBinaryTree(root->left, data);
        } else {
            root->right = insertFullBinaryTree(root->right, data);
        }
    }
    return root;
}

void inOrder(Node *&root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node *root = NULL;

    root = insertFullBinaryTree(root, 1);
    insertFullBinaryTree(root, 2);
    insertFullBinaryTree(root, 3);
    insertFullBinaryTree(root, 4);
    insertFullBinaryTree(root, 5);
    insertFullBinaryTree(root, 6);
    insertFullBinaryTree(root, 7);

    inOrder(root);
}