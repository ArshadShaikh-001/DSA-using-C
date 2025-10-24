#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function prototypes
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtPosition(int, int);
void traverse();
void deleteAtBeginning();
void deleteAtEnd();
void deleteSpecific(int);
void countElements();
void searchElement(int);
void traverseReverse(struct Node*);

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Traverse List\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete Specific Element\n");
        printf("8. Count Elements\n");
        printf("9. Search Element\n");
        printf("10. Traverse in Reverse Order\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtPosition(value, pos);
            break;
        case 4:
            traverse();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteSpecific(value);
            break;
        case 8:
            countElements();
            break;
        case 9:
            printf("Enter value to search: ");
            scanf("%d", &value);
            searchElement(value);
            break;
        case 10:
            printf("List in Reverse: ");
            traverseReverse(head);
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Insert functions
void insertAtBeginning(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", val);
}

void insertAtEnd(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", val);
}

void insertAtPosition(int val, int pos) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("Position not found.\n");
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Traverse
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Delete functions
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted first element.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Deleted last element.\n");
}

void deleteSpecific(int val) {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Deleted element %d.\n", val);
}

// Count elements
void countElements() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total elements: %d\n", count);
}

// Search element
void searchElement(int val) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element %d found at position %d.\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found.\n");
}

// Reverse traversal using recursion
void traverseReverse(struct Node* node) {
    if (node == NULL)
        return;
    traverseReverse(node->next);
    printf("%d ", node->data);
}
