#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

void enqueue(Queue* queue, int person) {
    if (queue->size == MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = person;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }
    int person = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return person;
}

int isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        exit(EXIT_FAILURE);
    }
    initializeQueue(queue);
    return queue;
}

void roundRobinDequeue(Queue** queues, int n) {
    int done = 0;
    while (!done) {
        done = 1;
        for (int i = 0; i < n; ++i) {
            if (!isQueueEmpty(queues[i])) {
                printf("%d ", dequeue(queues[i]));
                done = 0;
            }
        }
    }
    printf("\n");
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int* arr = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arr[i]);
    }

    Queue** queues = (Queue**)malloc(n * sizeof(Queue*));
    for (int i = 0; i < n; ++i) {
        queues[i] = createQueue();
    }

    int index = 0;
    for (int i = 0; i < m; ++i) {
        enqueue(queues[index], arr[i]);
        if ((i + 1) % (m / n) == 0 && index < n - 1) {
            index++;
        }
    }

    roundRobinDequeue(queues, n);

    free(arr);
    for (int i = 0; i < n; ++i) {
        free(queues[i]);
    }
    free(queues);

    return 0;
}
