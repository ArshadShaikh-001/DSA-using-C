#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of the queue

// Structure definition
struct Queue {
    int data[SIZE];  // Array used to store queue elements
    int front, rear; // Front and rear indices
};

// Function declarations
void enqueue(struct Queue *q, int value);
void dequeue(struct Queue *q);
void traverse(struct Queue q);

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;

    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Traverse (Display)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                traverse(q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to insert element into queue
void enqueue(struct Queue *q, int value) {
    if (q->rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert element.\n");
    } else {
        if (q->front == -1)  // If inserting first element
            q->front = 0;
        q->rear++;
        q->data[q->rear] = value;  // Array is used here
        printf("%d inserted into queue.\n", value);
    }
}

// Function to delete element from queue
void dequeue(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow! No element to delete.\n");
    } else {
        printf("%d deleted from queue.\n", q->data[q->front]);  // Array accessed here
        q->front++;
    }
}

// Function to traverse the queue
void traverse(struct Queue q) {
    if (q.front == -1 || q.front > q.rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements (front to rear):\n");
        for (int i = q.front; i <= q.rear; i++)
            printf("%d ", q.data[i]);  // Array used here
        printf("\n");
    }
}
