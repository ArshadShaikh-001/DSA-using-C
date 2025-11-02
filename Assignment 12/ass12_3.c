#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int stack[MAX], top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void DFS_Recursive(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS_Recursive(i);
    }
}

void DFS_NonRecursive(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    push(start);
    visited[start] = 1;
    printf("DFS (Non-Recursive): ");
    while (top != -1) {
        int v = pop();
        printf("%d ", v);
        for (int i = n - 1; i >= 0; i--) {
            if (graph[v][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void BFS_NonRecursive(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    front = rear = -1;
    enqueue(start);
    visited[start] = 1;
    printf("BFS (Non-Recursive): ");
    while (front != -1 && front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void BFS_Recursive_Helper(int v) {
    if (front == -1 || front > rear)
        return;
    int current = dequeue();
    printf("%d ", current);
    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            enqueue(i);
            visited[i] = 1;
        }
    }
    BFS_Recursive_Helper(v);
}

void BFS_Recursive(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    front = rear = -1;
    enqueue(start);
    visited[start] = 1;
    printf("BFS (Recursive): ");
    BFS_Recursive_Helper(start);
    printf("\n");
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0-%d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++) visited[i] = 0;
    printf("DFS (Recursive): ");
    DFS_Recursive(start);
    printf("\n");

    DFS_NonRecursive(start);
    BFS_NonRecursive(start);
    BFS_Recursive(start);

    return 0;
}
