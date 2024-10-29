#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }
    
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insert_into_heap(int heap[], int *heap_size, int k, int value) {
    if (*heap_size < k) {
        heap[(*heap_size)++] = value;
        for (int i = *heap_size / 2 - 1; i >= 0; i--) {
            heapify(heap, *heap_size, i);
        }
    } else if (value > heap[0]) {
        heap[0] = value;
        heapify(heap, k, 0);
    }
}

void print_heap(int heap[], int heap_size) {
    int temp[heap_size];
    for (int i = 0; i < heap_size; i++) {
        temp[i] = heap[i];
    }
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify(temp, heap_size, i);
    }
    
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

int main() {
    int k, n;
    scanf("%d", &k);
    scanf("%d", &n);
    
    int heap[k];
    int heap_size = 0;
    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert_into_heap(heap, &heap_size, k, value);
        print_heap(heap, heap_size);
    }
    
    // Sorting the final heap for output
    for (int i = 0; i < heap_size; i++) {
        for (int j = i + 1; j < heap_size; j++) {
            if (heap[i] > heap[j]) {
                swap(&heap[i], &heap[j]);
            }
        }
    }
    
    printf("K largest elements are:\n");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    
    return 0;
}