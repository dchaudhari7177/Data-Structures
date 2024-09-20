//Josephous problem

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} CircularLinkedList;

void initList(CircularLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insertEnd(CircularLinkedList *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = list->head; 
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = list->head;  
    }
    list->size++;
}

void deleteNode(CircularLinkedList *list, Node *prev, Node *current) {
    if (list->size == 1) {
        free(current);
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return;
    }

    prev->next = current->next;  
    if (current == list->head) {
        list->head = current->next;  
    }
    if (current == list->tail) {
        list->tail = prev;  
    }

    free(current);
    list->size--;
}

void josephus(CircularLinkedList *list, int k) {
    Node *current = list->head;
    Node *prev = list->tail;  

    while (list->size > 3) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        deleteNode(list, prev, current);
        current = prev->next; 
    }
}

void printList(CircularLinkedList *list) {
    if (list->head == NULL) {
        return;
    }

    Node *current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("\n");
}

void destroyList(CircularLinkedList *list) {
    if (list->head != NULL) {
        Node *p = list->head;

        while (p != list->tail) {
            list->head = p->next;
            list->tail->next = p->next;
            free(p);
            p = list->head;
        }
        free(p);
        list->head = NULL;
        list->tail = NULL;
    }
}

int main() {
    int n, k;
    CircularLinkedList list;

    initList(&list);

    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 1; i <= n; i++) {
        insertEnd(&list, i);
    }

    josephus(&list, k);
    printList(&list);
    destroyList(&list);

    return 0;
}