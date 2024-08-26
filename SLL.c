#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
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
    n->next = l->head;
    l->head = n;

    printf("Element inserted successfully\n");
}

void insertPos(LIST *l){
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
    temp->next = NULL;

    if (l->head == NULL && pos == 0) {
        printf("Inserted at position 0, as the list is empty\n");
        l->head = temp;
    } else {
        node* present = l->head;
        node* previous = NULL;
        int valid = 1;

        for (int i = 0; i < pos; i++) {
            if (present == NULL) {
                printf("Invalid Position\n");
                valid = 0;
                break;
            } else {
                previous = present;
                present = present->next;
            }
        }

        if (valid) {
            if (previous == NULL) { // Inserting at the head (position 0)
                temp->next = l->head;
                l->head = temp;
            } else {
                previous->next = temp;
                temp->next = present;
            }
            printf("Element inserted at position %d successfully\n", pos);
        }
    }
}

void insertEnd(LIST* l) {
    int a;
    printf("Enter the number to insert in the list: ");
    scanf("%d", &a);

    node* p = (node*)malloc(sizeof(node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    p->data = a;
    p->next = NULL;

    if (l->head == NULL) {
        l->head = p;
    } else {
        node* n = l->head;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = p;
    }

    printf("Element inserted at end successfully\n");
}

void deleteFront(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* n = l->head;
    l->head = l->head->next;
    free(n);

    printf("Element deleted from front successfully\n");
}

void deleteLast(LIST *l) {
    if (l->head == NULL) {
        printf("Empty list\n");
        return;
    }

    node* present = l->head;
    node* previous = NULL;

    while (present->next != NULL) {
        previous = present;
        present = present->next;
    }

    free(present);

    if (previous != NULL) {
        previous->next = NULL;
    } else {
        l->head = NULL; 
    }

    printf("Element deleted from end successfully\n");
}

void deletePos(LIST *l) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (l->head == NULL) {
        printf("List is Empty\n");
        return;
    }

    node* present = l->head;
    node* previous = NULL;

    if (pos == 0) {
        l->head = present->next;
        free(present);
        printf("Element deleted from position 0 successfully\n");
        return;
    }

    for (int i = 0; i < pos; i++) {
        if (present == NULL) {
            printf("Invalid Position\n");
            return;
        } else {
            previous = present;
            present = present->next;
        }
    }

    if (present != NULL) {
        previous->next = present->next;
        free(present);
        printf("Element deleted from position %d successfully\n", pos);
    }
}

void search(LIST *l) {
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int pos = 0;
    node* present = l->head;

    if (present == NULL) {
        printf("The list is Empty\n");
        return;
    }

    while (present != NULL) {
        if (present->data == x) {
            printf("Element found at position: %d\n", pos);
            return;
        }
        present = present->next;
        pos++;
    }
    printf("Element is not found in the list\n");
}

void deleteList(LIST *l) {
    if (l->head == NULL) {
        printf("Empty list\n");
        return;
    }

    node* temp;
    while (l->head != NULL) {
        temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}

void display(LIST* l) {
    if (l->head == NULL) {
        printf("List is Empty\n");
        return;
    }

    node* n = l->head;
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }

    printf("\n");
}

int main() {
    LIST list;
    initialize(&list);
    int ch;

    do {
        printf("1. InsertFront\t2. InsertEnd\t3. Display\t4. DeleteFront\t5. DeleteLast\t6. DeletePos\t7. Search\t8. InsertPos\t9.deleteList\t10. Exit\n");
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
    } while (ch != 9);

    return 0;
}
