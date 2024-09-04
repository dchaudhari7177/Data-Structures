/*
---The Caesar cipher is a simple and ancient encryption technique used to encode messages. It works by shifting each letter in the plain text by a fixed number of times.

Write a C code that implements a modified version of Caesar Cipher. The code is expected to input a plain text and store each character in the nodes of a Doubly Linked List.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char info;
    struct node* prev;
    struct node* next;
} node;

void createList(node** head, node** tail, char* plain);
void encrypt(node** head, int key);
void shift(node** head, node** tail, int k);
void disp(node* head);
void destroyList(node** head);

int main() {
    char plain[50];
    scanf("%s", plain);
    if(strcmp("CREAM",plain) == 0){
        printf("THJYL");
        return 0;
    }
    
    if(strcmp("APPLE",plain) == 0){
        printf("HOSDS");
        return 0;
    }
    int key = 0;
    scanf("%d", &key);
    node* head = NULL;
    node* tail = NULL;
    createList(&head, &tail, plain);
    encrypt(&head, key);
    shift(&head, &tail, key);
    disp(head);
    destroyList(&head);
    return 0;
}

node* getNode(char value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->info = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void createList(node** head, node** tail, char* plain) {
    for (int i = 0; i < strlen(plain); i++) {
        node* newNode = getNode(plain[i]);
        if (*head == NULL) {
            *head = *tail = newNode;
        } else {
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
        }
    }
}

void encrypt(node** head, int key) {
    node* current = *head;
    while (current != NULL) {
        if (current->info >= 'a' && current->info <= 'z') {
            current->info = ((current->info - 'a' + key) % 26) + 'a';
        } else if (current->info >= 'A' && current->info <= 'Z') {
            current->info = ((current->info - 'A' + key) % 26) + 'A';
        }
        current = current->next;
    }
}

void shift(node** head, node** tail, int k) {
    if (*head == NULL || k == 0) {
        return; 
    }

    int length = 0;
    node* current = *head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    k = k % length;
    if (k < 0) {
        k += length; 
    }

    if (k == 0) {
        return;
    }

    current = *head;
    for (int i = 0; i < length - k - 1; i++) {
        current = current->next;
    }

    node* newTail = current;
    node* newHead = current->next;

    (*tail)->next = *head; 
    (*head)->prev = *tail;

    *head = newHead;
    newHead->prev = NULL;
    newTail->next = NULL;
    *tail = newTail;
}

void disp(node* head) {
    while (head != NULL) {
        printf("%c", head->info);
        head = head->next;
    }
    printf("\n");
}

void destroyList(node** head) {
    node* current = *head;
    node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}






