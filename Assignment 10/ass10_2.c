#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Queue structure
struct Queue {
    char names[MAX][50];  
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void addCustomer(struct Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more customers.\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    strcpy(q->names[q->rear], name);
    printf("Customer %s has joined the queue.\n", name);
}

void processBooking(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No customers in the queue to process.\n");
        return;
    }

    printf("Booking processed for customer: %s\n", q->names[q->front]);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void viewQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No customers in the queue.\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s", q->names[i]);
        if (i < q->rear)
            printf(" -> ");
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice;
    char name[50];

    printf("--- Welcome to ABC Ticket Booking System ---\n");

    while (1) {
        printf("\n1. Add Customer\n");
        printf("2. Process Booking\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("Enter Your Choice (1-4): ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter Customer Name: ");
                scanf("%[^\n]", name);
                addCustomer(&q, name);
                break;

            case 2:
                processBooking(&q);
                break;

            case 3:
                viewQueue(&q);
                break;

            case 4:
                printf("Thank you for using ABC Ticket Booking System!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
