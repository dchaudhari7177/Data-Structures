/*
---Write a recursive C function that takes an array of integers ,reverses them and checks if it is the same as the initial array. Prints “Same” if array and its reverse are the same else prints “Not the same”.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void recursion(int* a, int size, int i) {
    if (i >= size / 2) {
        printf("Same\n");
        return;
    }
    if (a[i] != a[size - 1 - i]) {
        printf("Not the same\n");
        return;
    }
    recursion(a, size, i + 1);
}

int main() {
    int size;
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    recursion(a, size, 0);
    return 0;
}
