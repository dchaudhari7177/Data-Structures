#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

void buildMaxHeap(int heap[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && heap[(j - 1) / 2] < heap[j]) {
            swap(&heap[(j - 1) / 2], &heap[j]);
            j = (j - 1) / 2;
        }
    }
}

void heapSort(int heap[], int n) {
    buildMaxHeap(heap, n);

    for (int i = n - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        maxHeapify(heap, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int heap[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[i]);
    }

    // Build the max heap using top-down construction
    buildMaxHeap(heap, n);

    // Print the heap in level order
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    // Sort the heap in ascending order
    heapSort(heap, n);

    // Print the sorted elements
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}