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
    n->next = l->head;
    n->prev = NULL;

    if (l->head != NULL) {
        l->head->prev = n;
    }
    l->head = n;

    printf("Element inserted successfully at the front\n");
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
        p->prev = NULL;
        l->head = p;
    } else {
        node* n = l->head;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = p;
        p->prev = n;
    }

    printf("Element inserted at end successfully\n");
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
    temp->prev = NULL;

    if (l->head == NULL && pos == 0) {
        printf("Inserted at position 0, as the list is empty\n");
        l->head = temp;
    } else {
        node* present = l->head;
        int valid = 1;

        for (int i = 0; i < pos; i++) {
            if (present == NULL) {
                printf("Invalid Position\n");
                valid = 0;
                break;
            } else {
                present = present->next;
            }
        }

        if (valid) {
            if (present == NULL) { 
                insertEnd(l);
            } else if (present->prev == NULL) { 
                temp->next = l->head;
                l->head->prev = temp;
                l->head = temp;
            } else { 
                temp->next = present;
                temp->prev = present->prev;
                present->prev->next = temp;
                present->prev = temp;
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
    l->head = l->head->next;

    if (l->head != NULL) {
        l->head->prev = NULL;
    }

    free(n);

    printf("Element deleted from front successfully\n");
}

void deleteLast(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* present = l->head;

    while (present->next != NULL) {
        present = present->next;
    }

    if (present->prev != NULL) {
        present->prev->next = NULL;
    } else {
        l->head = NULL;
    }

    free(present);

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
        if (present == NULL) {
            printf("Invalid Position\n");
            return;
        }
        present = present->next;
    }

    if (present == NULL) {
        printf("Invalid Position\n");
        return;
    }

    if (present->prev != NULL) {
        present->prev->next = present->next;
    } else {
        l->head = present->next;
    }

    if (present->next != NULL) {
        present->next->prev = present->prev;
    }

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

    while (present != NULL) {
        if (present->data == x) {
            printf("Element found at position: %d\n", pos);
            return;
        }
        present = present->next;
        pos++;
    }
    printf("Element not found in the list\n");
}

void deleteList(LIST* l) {
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
    printf("List deleted successfully");
}

void display(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
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
    } while (ch != 9);

    return 0;
}
