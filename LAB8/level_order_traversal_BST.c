#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Definition of a node in the Binary Search Tree (BST)
typedef struct node {
    int info;
    struct node* left;
    struct node* right;
} NODE;

// Definition of a tree
typedef struct tree {
    NODE *root;
} TREE;

// Queue for Level Order Traversal
typedef struct queue {
    NODE* data[MAX];
    int front, rear;
} QUEUE;

// Function prototypes
void initTree(TREE *pt);
NODE* createNode(int ele);
void constructTree(TREE *pt, int ele);
void levelOrder(TREE *pt);
void destroyTreeHelper(NODE* root);
void destroyTree(TREE *pt);
void initQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);
void enqueue(QUEUE *pq, NODE* x);
NODE* dequeue(QUEUE *pq);

// Main function
int main() {
    TREE tobj;
    initTree(&tobj);
    
    int n, ele;
    scanf("%d", &n);  // Number of elements to be inserted

    for (int i = 0; i < n; i++) {
        scanf("%d", &ele);  // Reading elements one by one
        constructTree(&tobj, ele);  // Constructing the BST
    }
    
    levelOrder(&tobj);  // Performing level order traversal
    
    destroyTree(&tobj);  // Destroying the tree and freeing memory
    
    return 0;
}

// Function to initialize the tree
void initTree(TREE *pt) {
    pt->root = NULL;
}

// Function to create a new node with given element
NODE* createNode(int ele) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to construct the BST by inserting elements
void constructTree(TREE *pt, int ele) {
    NODE *newNode = createNode(ele);
    
    if (pt->root == NULL) {
        pt->root = newNode;
        return;
    }
    
    NODE *current = pt->root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (ele < current->info) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (ele < parent->info) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function to perform level order traversal
void levelOrder(TREE *pt) {
    if (pt->root == NULL) {
        return;
    }

    QUEUE q;
    initQueue(&q);
    enqueue(&q, pt->root);

    while (!isEmpty(&q)) {
        NODE* current = dequeue(&q);
        printf("%d ", current->info);

        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    printf("\n");
}

// Function to destroy the tree by freeing all nodes
void destroyTreeHelper(NODE* root) {
    if (root == NULL) {
        return;
    }
    
    destroyTreeHelper(root->left);
    destroyTreeHelper(root->right);
    free(root);
}

// Function to destroy the tree and set the root to NULL
void destroyTree(TREE *pt) {
    destroyTreeHelper(pt->root);
    pt->root = NULL;
}

// Queue functions for level order traversal
void initQueue(QUEUE *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int isEmpty(QUEUE *pq) {
    return pq->front == pq->rear;
}

void enqueue(QUEUE *pq, NODE* x) {
    if (pq->rear == MAX) {
        return;  // Queue overflow
    }
    pq->data[pq->rear++] = x;
}

NODE* dequeue(QUEUE *pq) {
    if (isEmpty(pq)) {
        return NULL;  // Queue underflow
    }
    return pq->data[pq->front++];
}
