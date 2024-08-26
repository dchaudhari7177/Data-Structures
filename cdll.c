#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct linkedlist {
    node* head;
} LIST;

void initialize(LIST* l) {
    l->head = NULL;
}

void insertFront(LIST* l) {
    int a;
    printf("Enter the number to insert in the list: ");
    scanf("%d", &a);

    node* n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = a;

    if (l->head == NULL) {
        n->next = n;
        n->prev = n;
        l->head = n;
    } else {
        node* last = l->head->prev;
        n->next = l->head;
        n->prev = last;
        l->head->prev = n;
        last->next = n;
        l->head = n;
    }

    printf("Element inserted successfully at the front\n");
}

void insertEnd(LIST* l) {
    int a;
    printf("Enter the number to insert in the list: ");
    scanf("%d", &a);

    node* n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = a;

    if (l->head == NULL) {
        n->next = n;
        n->prev = n;
        l->head = n;
    } else {
        node* last = l->head->prev;
        last->next = n;
        n->prev = last;
        n->next = l->head;
        l->head->prev = n;
    }

    printf("Element inserted at end successfully\n");
}

void insertPos(LIST* l) {
    int pos, x;
    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);
    printf("Enter the element: ");
    scanf("%d", &x);

    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = x;

    if (l->head == NULL && pos == 0) {
        temp->next = temp;
        temp->prev = temp;
        l->head = temp;
        printf("Inserted at position 0, as the list is empty\n");
    } else {
        node* present = l->head;
        int valid = 1;

        for (int i = 0; i < pos; i++) {
            if (present->next == l->head) {
                printf("Invalid Position\n");
                valid = 0;
                break;
            } else {
                present = present->next;
            }
        }

        if (valid) {
            node* prevNode = present->prev;
            temp->next = present;
            temp->prev = prevNode;
            prevNode->next = temp;
            present->prev = temp;
            if (pos == 0) {
                l->head = temp;
            }
            printf("Element inserted at position %d successfully\n", pos);
        }
    }
}

void deleteFront(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* n = l->head;

    if (l->head->next == l->head) {
        l->head = NULL;
    } else {
        node* last = l->head->prev;
        l->head = l->head->next;
        l->head->prev = last;
        last->next = l->head;
    }

    free(n);

    printf("Element deleted from front successfully\n");
}

void deleteLast(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* last = l->head->prev;

    if (l->head->next == l->head) {
        l->head = NULL;
    } else {
        node* secondLast = last->prev;
        secondLast->next = l->head;
        l->head->prev = secondLast;
    }

    free(last);

    printf("Element deleted from end successfully\n");
}

void deletePos(LIST* l) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* present = l->head;

    for (int i = 0; i < pos; i++) {
        if (present->next == l->head) {
            printf("Invalid Position\n");
            return;
        }
        present = present->next;
    }

    node* prevNode = present->prev;
    node* nextNode = present->next;

    if (present == l->head) {
        if (l->head->next == l->head) {
            l->head = NULL;
        } else {
            l->head = nextNode;
        }
    }

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    free(present);

    printf("Element deleted from position %d successfully\n", pos);
}

void search(LIST* l) {
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int pos = 0;
    node* present = l->head;

    if (present == NULL) {
        printf("The list is empty\n");
        return;
    }

    do {
        if (present->data == x) {
            printf("Element found at position: %d\n", pos);
            return;
        }
        present = present->next;
        pos++;
    } while (present != l->head);

    printf("Element not found in the list\n");
}

void deleteList(LIST* l) {
    if (l->head == NULL) {
        printf("Empty list\n");
        return;
    }

    node* temp;
    while (l->head->next != l->head) {
        temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
    free(l->head);
    l->head = NULL;

    printf("List deleted successfully\n");
}

void display(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* n = l->head;
    do {
        printf("%d ", n->data);
        n = n->next;
    } while (n != l->head);

    printf("\n");
}

int main() {
    LIST list;
    initialize(&list);
    int ch;

    do {
        printf("1. InsertFront\t2. InsertEnd\t3. Display\t4. DeleteFront\t5. DeleteLast\t6. DeletePos\t7. Search\t8. InsertPos\t9. deleteList \t10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insertFront(&list); break;
            case 2: insertEnd(&list); break;
            case 3: display(&list); break;
            case 4: deleteFront(&list); break;
            case 5: deleteLast(&list); break;
            case 6: deletePos(&list); break;
            case 7: search(&list); break;
            case 8: insertPos(&list); break;
            case 9: deleteList(&list); break;
            case 10: printf("Thank you!\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 10);

    return 0;
}
