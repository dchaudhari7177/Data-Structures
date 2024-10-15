#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert nodes in level order
struct TreeNode* insertLevelOrder(int* arr, struct TreeNode* root, int i, int n) {
    if (i < n && arr[i] != -1) {
        struct TreeNode* temp = newNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Helper function to perform in-order traversal and find kth smallest element
void inorderTraversal(struct TreeNode* root, int* count, int k, int* result) {
    if (root == NULL || *count >= k)
        return;
    inorderTraversal(root->left, count, k, result);
    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }
    inorderTraversal(root->right, count, k, result);
}

// Function to find the kth smallest element in the BST
int kthSmallest(struct TreeNode* root, int k) {
    int result = -1;  
    int count = 0;    
    inorderTraversal(root, &count, k, &result);
    return result;
}

int main() {
    int n, k;
    scanf("%d", &n);  
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);  
    // Create the BST using the input
    struct TreeNode* root = insertLevelOrder(arr, NULL, 0, n);
    // Find the kth smallest element
    int result = kthSmallest(root, k);
    // Output the result
    printf("%d\n", result);
    return 0;
}