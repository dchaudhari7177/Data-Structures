#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100

void findDegrees(int edges[][2], int numEdges, int degrees[], int maxNode);

int main() {
    int numEdges;
    scanf("%d", &numEdges);
    int edges[MAX_NODES][2];
    int degrees[MAX_NODES] = {0}; // Initialize degrees to 0
    int maxNode = 0;
    // Input edges and determine the maximum node number
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        if (edges[i][0] > maxNode) {
            maxNode = edges[i][0];
        }
        if (edges[i][1] > maxNode) {
            maxNode = edges[i][1];
        }
    }
    // Calculate degrees
    findDegrees(edges, numEdges, degrees, maxNode);
    // Output degrees
    printf("Degrees of each node:\n");
    for (int i = 0; i <= maxNode; i++) {
        printf("Node %d: %d\n", i, degrees[i]);
    }
    return 0;
}

void findDegrees(int edges[][2], int numEdges, int degrees[], int maxNode) {
    bool counted[MAX_NODES][MAX_NODES] = {false}; 
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (u == v) {
            if (!counted[u][v]) {
                degrees[u]++;
                counted[u][v] = true; 
            }
        } 
        else {
            if (u > v) {
                int temp = u;
                u = v;
                v = temp;
            }
            if (!counted[u][v]) {
                degrees[u]++;
                degrees[v]++;
                counted[u][v] = true; 
            }
        }
    }
}