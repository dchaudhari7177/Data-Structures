#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data);

// Function to insert values into the binary search tree
struct Node* insert(struct Node* root, int data);

// Function to check if two nodes are at the same depth from a given starting node
int checkEqualDepth(struct Node* root, int node1, int node2);

// Helper function to get the depth of a node
int getDepth(struct Node* root, int value, int depth);

// Destroys all nodes in a Binary search tree and sets root = NULL
struct Node* destroyTree(struct Node *root);

int main() {
    struct Node* root = NULL;
    int n, i, data;

    // Input number of nodes to insert
    scanf("%d", &n);

    // Insert nodes into the binary search tree
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    int node1, node2;

    // Input the two search nodes
    scanf("%d", &node1);
    scanf("%d", &node2);

    // Check if the two nodes are at equal depth
    int result = checkEqualDepth(root, node1, node2);

    // Print the result
    if (result == 1) {
        printf("Nodes are at the same depth");
    } else {
        printf("Nodes are not at the same depth");
    }

    root = destroyTree(root);

    return 0;
}

// Function to check if two nodes are at the same depth from a given starting node
int checkEqualDepth(struct Node* root, int node1, int node2) {
    int depth1 = getDepth(root, node1, 0);
    int depth2 = getDepth(root, node2, 0);

    if (depth1 == depth2) {
        return 1;
    } else {
        return 0;
    }
}

// Helper function to get the depth of a node
int getDepth(struct Node* root, int value, int depth) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == value) {
        return depth;
    }

    if (value < root->data) {
        return getDepth(root->left, value, depth + 1);
    } else {
        return getDepth(root->right, value, depth + 1);
    }
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert values into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Destroys all nodes in a Binary search tree and sets root = NULL
struct Node* destroyTree(struct Node *root) {
    if (root != NULL) {
        root->left = destroyTree(root->left);
        root->right = destroyTree(root->right);
        free(root);
    }
    return NULL;
}
