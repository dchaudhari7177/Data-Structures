/*
--Write a C program that takes 2 polynomials, adds them and evaluate it with an input value(x). If the resultant linked list is empty print -1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int degree;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coefficient, int degree) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->degree = degree;
    newNode->next = NULL;
    return newNode;
}

// Function to input terms of the polynomial
Node* input(int terms) {
    Node* head = NULL;
    Node* temp = NULL;
    int coefficient, degree;

    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coefficient, &degree);
        Node* newNode = createNode(coefficient, degree);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

// Function to find the sum of two polynomials
Node* sum(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        Node* newNode;
        if (poly1->degree > poly2->degree) {
            newNode = createNode(poly1->coefficient, poly1->degree);
            poly1 = poly1->next;
        } else if (poly1->degree < poly2->degree) {
            newNode = createNode(poly2->coefficient, poly2->degree);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                newNode = createNode(sumCoeff, poly1->degree);
            } else {
                poly1 = poly1->next;
                poly2 = poly2->next;
                continue;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    while (poly1 != NULL) {
        Node* newNode = createNode(poly1->coefficient, poly1->degree);
        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        Node* newNode = createNode(poly2->coefficient, poly2->degree);
        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        poly2 = poly2->next;
    }

    return result;
}

// Function to evaluate the polynomial with the given value x
int eval(Node* poly, int x) {
    int result = 0;

    while (poly != NULL) {
        int termValue = poly->coefficient;
        for (int i = 0; i < poly->degree; i++) {
            termValue *= x;
        }
        result += termValue;
        poly = poly->next;
    }

    return result;
}

// Function to free all nodes in the linked list
void destroy(Node* poly) {
    while (poly != NULL) {
        Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    int m, n, x;
    scanf("%d %d", &m, &n);
    scanf("%d", &x);

    Node* poly1 = input(m);
    Node* poly2 = input(n);

    Node* resultPoly = sum(poly1, poly2);

    if (resultPoly == NULL) {
        printf("-1\n");
    } else {
        int result = eval(resultPoly, x);
        printf("%d\n", result);
    }

    destroy(poly1);
    destroy(poly2);
    destroy(resultPoly);

    return 0;
}

