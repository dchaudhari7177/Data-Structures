#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int x) {
    if (q->size == MAX_QUEUE_SIZE) {
        return; // Queue is full
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = x;
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0) {
        return -1; 
    }
    int element = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return element;
}

int front(Queue* q) {
    if (q->size == 0) {
        return -1; 
    }
    return q->data[q->front];
}

bool isQueueEmpty(Queue* q) {
    return q->size == 0;
}

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);
    while (!isQueueEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    return front(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

int main() {
    int n;

    scanf("%d", &n);

    char operations[n][10];  
    int values[n];  
    memset(values, 0, sizeof(values));  

    char result[n][10]; 
    memset(result, 0, sizeof(result));  

    for (int i = 0; i < n; i++) {
        scanf("%s", operations[i]);
        if (strcmp(operations[i], "push") == 0) {
            scanf("%d", &values[i]);
        }
    }

    MyStack* stack = NULL;

    for (int i = 0; i < n; i++) {
        if (strcmp(operations[i], "MyStack") == 0 || strcmp(operations[i], "stack") == 0) {
            stack = myStackCreate();
            strcpy(result[i], "null");
        } else if (strcmp(operations[i], "push") == 0) {
            myStackPush(stack, values[i]);
            strcpy(result[i], "null");
        } else if (strcmp(operations[i], "pop") == 0) {
            int poppedValue = myStackPop(stack);
            if (poppedValue != -1) {
                sprintf(result[i], "%d", poppedValue);
            } else {
                strcpy(result[i], "null");
            }
        } else if (strcmp(operations[i], "top") == 0) {
            int topValue = myStackTop(stack);
            if (topValue != -1) {
                sprintf(result[i], "%d", topValue);
            } else {
                strcpy(result[i], "null");
            }
        } else if (strcmp(operations[i], "empty") == 0) {
            if (myStackEmpty(stack)) {
                strcpy(result[i], "true");
            } else {
                strcpy(result[i], "false");
            }
        } else {
            strcpy(result[i], "invalid");
        }
    }

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%s", result[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    if (stack != NULL) {
        myStackFree(stack);
    }
    return 0;
}