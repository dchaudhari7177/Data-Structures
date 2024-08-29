/*
--In the town of Linked Junction, a young conductor faces a magical challenge: two trains must be merged into one grand, mystical train. Each train’s carriages have numbers and are already sorted & can connect to both their previous & next carriages, allowing passengers to travel safely in either direction. To maintain the magic, the conductor must merge the two trains while preserving the sorted order. If the sequence breaks, the magic fades, and the passengers lose their way.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} NODE;

NODE* InsertEnd(NODE* tail, int value) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        return tail;
    }
    
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = tail;
    
    if (tail == NULL) {
        return newNode; 
    } else {
        tail->next = newNode;
        return newNode; 
    }
}

void PrintList(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

NODE* MergeTrains(NODE* list1, NODE* list2) {
    NODE* merged = NULL;
    NODE* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            if (merged == NULL) {
                merged = tail = list1;
            } else {
                tail->next = list1;
                list1->prev = tail;
                tail = list1;
            }
            list1 = list1->next;
        } else {
            if (merged == NULL) {
                merged = tail = list2;
            } else {
                tail->next = list2;
                list2->prev = tail;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        if (merged == NULL) {
            merged = list1;
        } else {
            tail->next = list1;
            list1->prev = tail;
        }
    } else if (list2 != NULL) {
        if (merged == NULL) {
            merged = list2;
        } else {
            tail->next = list2;
            list2->prev = tail;
        }
    }

    return merged;
}

NODE* FreeList(NODE* head) {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main() {
    NODE* list1 = NULL;
    NODE* tail1 = NULL;
    NODE* list2 = NULL;
    NODE* tail2 = NULL;
    int n1, n2, value;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        if (list1 == NULL) {
            list1 = tail1 = InsertEnd(NULL, value);
        } else {
            tail1 = InsertEnd(tail1, value);
        }
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        if (list2 == NULL) {
            list2 = tail2 = InsertEnd(NULL, value);
        } else {
            tail2 = InsertEnd(tail2, value);
        }
    }

    NODE* mergedtrain = MergeTrains(list1, list2);

    PrintList(mergedtrain);
   
    mergedtrain = FreeList(mergedtrain);

    return 0;
}
