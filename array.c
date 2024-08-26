#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct abc {
    int last;
    int arr[max];
} ARRAYLIST;

void initlast(ARRAYLIST *al) {
    al->last = -1;
}

void insertStart(ARRAYLIST *al, int ele) {
    if (al->last >= max - 1) {
        printf("Array List is full!\n");
        return;
    }
    for (int i = al->last; i >= 0; i--) {
        al->arr[i + 1] = al->arr[i];
    }
    al->arr[0] = ele;
    al->last++;
}

void insertLast(ARRAYLIST *al, int ele) {
    if (al->last >= max - 1) {
        printf("Array List is full!\n");
        return;
    }
    al->arr[++(al->last)] = ele;
}

void insertPos(ARRAYLIST *al, int ele, int pos) {
    if (al->last >= max - 1) {
        printf("Array List is full!\n");
        return;
    }
    if (pos < 0 || pos > al->last + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = al->last; i >= pos; i--) {
        al->arr[i + 1] = al->arr[i];
    }
    al->arr[pos] = ele;
    al->last++;
}

void display(ARRAYLIST *al) {
    if (al->last == -1) {
        printf("Array List is empty!\n");
        return;
    }
    printf("Array List: ");
    for (int i = 0; i <= al->last; i++) {
        printf("%d ", al->arr[i]);
    }
    printf("\n");
}

void search(ARRAYLIST *al, int ele) {
    for (int i = 0; i <= al->last; i++) {
        if (al->arr[i] == ele) {
            printf("Element %d found at position %d\n", ele, i);
            return;
        }
    }
    printf("Element %d not found in the Array List\n", ele);
}

int main() {
    ARRAYLIST al;
    initlast(&al);
    int choice, ele, pos;
   
    do {
        printf("\nEnter The Choice from following:\n");
        printf("1. Insert start\n2. Insert last\n3. Insert position\n4. Display\n5. Search\n6. DeleteLast\n7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                printf("Enter element to insert at start: ");
                scanf("%d", &ele);
                insertStart(&al, ele);
                break;
            case 2:
                printf("Enter element to insert at last: ");
                scanf("%d", &ele);
                insertLast(&al, ele);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPos(&al, ele, pos);
                break;
            case 4:
                display(&al);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                search(&al, ele);
                break;
            case 6:
                
                printf("thank you\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 6);
   
    return 0;
}
