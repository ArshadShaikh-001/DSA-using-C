#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of stack

// Structure definition
struct Stack {
    int data[SIZE];
    int top;
};

// Function declarations
void push(struct Stack *s, int value);
void pop(struct Stack *s);
void traverse(struct Stack s);

int main() {
    struct Stack s;
    s.top = -1; // Initialize stack
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Insert (Push)\n");
        printf("2. Delete (Pop)\n");
        printf("3. Traverse (Display)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                push(&s, value);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                traverse(s);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to insert element into stack
void push(struct Stack *s, int value) {
    if (s->top == SIZE - 1)
        printf("Stack Overflow! Cannot insert element.\n");
    else {
        s->top++;
        s->data[s->top] = value;
        printf("%d inserted into stack.\n", value);
    }
}

// Function to delete element from stack
void pop(struct Stack *s) {
    if (s->top == -1)
        printf("Stack Underflow! No element to delete.\n");
    else {
        printf("%d deleted from stack.\n", s->data[s->top]);
        s->top--;
    }
}

// Function to traverse stack elements
void traverse(struct Stack s) {
    if (s.top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements (top to bottom):\n");
        for (int i = s.top; i >= 0; i--)
            printf("%d\n", s.data[i]);
    }
}
