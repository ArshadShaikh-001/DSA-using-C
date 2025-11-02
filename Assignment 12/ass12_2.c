#include <stdio.h>

#define MAX 10

int main() {
    int graph[MAX][MAX];
    int n, i, j;

    printf("Enter number of landmarks (nodes): ");
    scanf("%d", &n);

    printf("\nEnter the distance between landmarks (0 if no direct road):\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Distance from Landmark %d to Landmark %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAdjacency Matrix (City Graph):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
