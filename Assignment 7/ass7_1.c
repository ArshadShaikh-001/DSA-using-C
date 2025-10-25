#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Insert at specific position (1-based index)
void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int i;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Traverse the list
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Count elements
int count() {
    if (head == NULL)
        return 0;
    int cnt = 0;
    struct Node* temp = head;
    do {
        cnt++;
        temp = temp->next;
    } while (temp != head);
    return cnt;
}

// Search element
void search(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found in the list.\n", key);
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* last = head;
    while (last->next != head)
        last = last->next;
    last->next = head->next;
    head = head->next;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// Delete specific element
void deleteElement(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    do {
        if (temp->data == key) {
            if (temp == head) {
                deleteAtBeginning();
            } else if (temp->next == head) {
                deleteAtEnd();
            } else {
                prev->next = temp->next;
                free(temp);
            }
            printf("Element %d deleted.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    printf("Element %d not found in the list.\n", key);
}

// Traverse in reverse using recursion
void traverseReverseUtil(struct Node* temp, struct Node* start) {
    if (temp->next != start)
        traverseReverseUtil(temp->next, start);
    printf("%d -> ", temp->data);
}

void traverseReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    traverseReverseUtil(head, head);
    printf("(head)\n");
}

// Menu
int main() {
    int choice, data, pos;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Traverse\n5. Delete at Beginning\n6. Delete at End\n7. Delete Element\n");
        printf("8. Count Elements\n9. Search Element\n10. Traverse Reverse\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
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
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteElement(data);
                break;
            case 8:
                printf("Number of elements: %d\n", count());
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 10:
                traverseReverse();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
