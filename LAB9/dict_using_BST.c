#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 25
#define MAX2 100

typedef struct node {
    char key[MAX1], value[MAX2];
    struct node *left, *right;
} NODE;

typedef struct tree {
    NODE* root;
} TREE;

// Function to initialize the tree
void init(TREE* pt);
// Function to create a new node
NODE* createNode(char word[MAX1], char meaning[MAX2]);
// Function to recursively insert a node into the BST
NODE* rinsert(NODE* r, NODE *temp);
// Function to insert a node into the tree
void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2]);
// Function for inorder traversal of the BST
void inorder(NODE* r);
// Function to delete a node from the BST
NODE* delNode(NODE* r, char word[MAX1]);
// Function for iterative search in the BST
int search(NODE* r, char word[MAX1]);
// Function to destroy all nodes in the tree
void destroyNode(NODE *r);
// Function to destroy the tree
void destroyTree(TREE *pt);

int main() {
    TREE tobj;
    init(&tobj);
    int num_operations;
    char word[MAX1], meaning[MAX2];
    int choice;

    // Reading number of operations
    scanf("%d", &num_operations);

    // Array to store search results (1 for success, 0 for failure)
    int search_results[num_operations];
    int search_index = 0;

    // Processing all operations
    for (int i = 0; i < num_operations; i++) {
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                scanf("%s", word);
                fflush(stdin);
                scanf(" %[^\n]", meaning);  // Input the meaning
                recInsert(&tobj, word, meaning);
                break;

            case 2: // Delete
                scanf("%s", word);
                tobj.root = delNode(tobj.root, word);
                break;

            case 3: // Search (results for search only)
                scanf("%s", word);
                if (search(tobj.root, word)) {
                    search_results[search_index++] = 1; // Search success
                } else {
                    search_results[search_index++] = 0; // Search failure
                }
                break;

            default:
                printf("Invalid operation\n");
        }
    }

    // Inorder traversal after all operations
    printf("Inorder Traversal:\n");
    inorder(tobj.root);

    // Print search results (1 for success, 0 for failure)
    printf("\nSearch Results:\n");
    for (int i = 0; i < search_index; i++) {
        printf("%d ", search_results[i]);
    }
    printf("\n");

    destroyTree(&tobj);
    return 0;
}


// Initialize the tree
void init(TREE* pt) {
    pt->root = NULL;
}

// Create a new node
NODE* createNode(char word[MAX1], char meaning[MAX2]) {
    NODE* temp = malloc(sizeof(NODE));
    strcpy(temp->key, word);
    strcpy(temp->value, meaning);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Recursively insert a node into the BST
NODE* rinsert(NODE* r, NODE *temp) {
    if (r == NULL)
        return temp;

    if (strcmp(temp->key, r->key) < 0) {
        r->left = rinsert(r->left, temp);
    } else if (strcmp(temp->key, r->key) > 0) {
        r->right = rinsert(r->right, temp);
    }

    return r;
}

// Insert a node into the tree
void recInsert(TREE *pt, char word[MAX1], char meaning[MAX2]) {
    NODE *temp = createNode(word, meaning);
    pt->root = rinsert(pt->root, temp);
}

// Inorder traversal of the BST
void inorder(NODE* r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%s, %s\n", r->key, r->value);  // Print key and value
        inorder(r->right);
    }
}

// Find the minimum value node in the right subtree (used in deletion)
NODE* findMin(NODE* r) {
    while (r->left != NULL)
        r = r->left;
    return r;
}

// Delete a node from the BST
NODE* delNode(NODE* r, char word[MAX1]) {
    if (r == NULL)
        return r;

    if (strcmp(word, r->key) < 0) {
        r->left = delNode(r->left, word);
    } else if (strcmp(word, r->key) > 0) {
        r->right = delNode(r->right, word);
    } else {
        // Node with only one child or no child
        if (r->left == NULL) {
            NODE *temp = r->right;
            free(r);
            return temp;
        } else if (r->right == NULL) {
            NODE *temp = r->left;
            free(r);
            return temp;
        }

        // Node with two children
        NODE* temp = findMin(r->right);
        strcpy(r->key, temp->key);
        strcpy(r->value, temp->value);
        r->right = delNode(r->right, temp->key);
    }
    return r;
}

// Iteratively search the BST
int search(NODE* r, char word[MAX1]) {
    while (r != NULL) {
        if (strcmp(word, r->key) == 0) {
            return 1;  // Found
        } else if (strcmp(word, r->key) < 0) {
            r = r->left;
        } else {
            r = r->right;
        }
    }
    return 0;  // Not found
}

// Destroy all nodes in the BST
void destroyNode(NODE *r) {
    if (r != NULL) {
        destroyNode(r->left);
        destroyNode(r->right);
        free(r);
    }
}

// Destroy the tree
void destroyTree(TREE *pt) {
    if (pt->root != NULL) {
        destroyNode(pt->root);
        pt->root = NULL;
    }
}
