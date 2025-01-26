#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node *createNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertLevelOrder(Node *&root, int data) {
    Node *newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
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

    insertLevelOrder(root, 1);
    insertLevelOrder(root, 2);
    insertLevelOrder(root, 3);
    insertLevelOrder(root, 4);
    insertLevelOrder(root, 5);

    inOrder(root);
}
