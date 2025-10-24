#include <stdio.h>
#define SIZE 100

typedef struct {
    int data;
    int next; // index of next node
} Node;

Node arr[SIZE];
int start = -1;  // start of linked list
int avail = 0;   // start of available list

// Initialize available list
void initialize() {
    for (int i = 0; i < SIZE - 1; i++)
        arr[i].next = i + 1;
    arr[SIZE - 1].next = -1;
}

// Allocate a node from available list
int getNode() {
    if (avail == -1) {
        printf("No space available!\n");
        return -1;
    }
    int newNode = avail;
    avail = arr[avail].next;
    return newNode;
}

// Free a node and add back to available list
void freeNode(int index) {
    arr[index].next = avail;
    avail = index;
}

// Insert at beginning
void insertAtBeginning(int value) {
    int newNode = getNode();
    if (newNode == -1) return;
    arr[newNode].data = value;
    arr[newNode].next = start;
    start = newNode;
}

// Delete first element
void deleteFirst() {
    if (start == -1) {
        printf("List is empty!\n");
        return;
    }
    int temp = start;
    start = arr[start].next;
    freeNode(temp);
    printf("First element deleted.\n");
}

// Traverse the list
void traverse() {
    if (start == -1) {
        printf("List is empty!\n");
        return;
    }
    int temp = start;
    printf("List elements: ");
    while (temp != -1) {
        printf("%d ", arr[temp].data);
        temp = arr[temp].next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    initialize();
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Traverse list\n");
        printf("3. Delete first element\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                traverse();
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}
