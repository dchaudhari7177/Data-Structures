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

    if (l->head == NULL) {
        n->next = n;
        l->head = n;
    } else {
        node* temp = l->head;
        while (temp->next != l->head) {
            temp = temp->next;
        }
        n->next = l->head;
        temp->next = n;
        l->head = n;
    }

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

    if (l->head == NULL) {
        p->next = p;
        l->head = p;
    } else {
        node* temp = l->head;
        while (temp->next != l->head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = l->head;
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

    if (l->head == NULL && pos == 0) {
        temp->next = temp;
        l->head = temp;
        printf("Inserted at position 0, as the list is empty\n");
    } else {
        node* present = l->head;
        node* prev = NULL;
        int i;

        for (i = 0; i < pos && present->next != l->head; i++) {
            prev = present;
            present = present->next;
        }

        if (i != pos) {
            printf("Invalid Position\n");
            free(temp);
            return;
        }

        temp->next = present;
        if (prev == NULL) {
            node* last = l->head;
            while (last->next != l->head) {
                last = last->next;
            }
            last->next = temp;
            l->head = temp;
        } else {
            prev->next = temp;
        }

        printf("Element inserted at position %d successfully\n", pos);
    }
}

void deleteFront(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = l->head;

    if (l->head->next == l->head) {
        l->head = NULL;
    } else {
        node* last = l->head;
        while (last->next != l->head) {
            last = last->next;
        }
        last->next = l->head->next;
        l->head = l->head->next;
    }

    free(temp);
    printf("Element deleted from front successfully\n");
}

void deleteLast(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = l->head;

    if (l->head->next == l->head) {
        l->head = NULL;
    } else {
        node* prev = NULL;
        while (temp->next != l->head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = l->head;
    }

    free(temp);
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

    node* temp = l->head;
    node* prev = NULL;
    int i;

    for (i = 0; i < pos && temp->next != l->head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos) {
        printf("Invalid Position\n");
        return;
    }

    if (prev == NULL) {
        deleteFront(l);
    } else {
        prev->next = temp->next;
        if (temp == l->head) {
            l->head = temp->next;
        }
        free(temp);
    }

    printf("Element deleted from position %d successfully\n", pos);
}

void search(LIST* l) {
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int pos = 0;
    node* temp = l->head;

    if (temp == NULL) {
        printf("The list is empty\n");
        return;
    }

    do {
        if (temp->data == x) {
            printf("Element found at position: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != l->head);

    printf("Element not found in the list\n");
}

void deleteList(LIST* l) {
    if (l->head == NULL) {
        printf("Empty list\n");
        return;
    }

    node* temp;
    node* current = l->head;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != l->head);

    l->head = NULL;
    printf("List deleted successfully\n");
}

void display(LIST* l) {
    if (l->head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = l->head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != l->head);

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
