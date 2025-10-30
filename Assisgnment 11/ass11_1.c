#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Stack {
    Node* items[MAX_STACK_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* st) {
    return st->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack* st) {
    return st->top == -1;
}

void push(Stack* st, Node* item) {
    if (isFull(st)) {
        printf("Stack Overflow\n");
        return;
    }
    st->items[++st->top] = item;
}

Node* pop(Stack* st) {
    if (isEmpty(st)) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return st->items[st->top--];
}

Node* peek(Stack* st) {
    if (isEmpty(st)) {
        return NULL;
    }
    return st->items[st->top];
}

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Constructs the expression tree from a postfix expression
Node* constructExpressionTree(char* postfix) {
    Stack* st = createStack();
    Node *t1, *t2, *newNode;

    for (int i = 0; postfix[i] != '\0'; i++) {
        // If character is an operand, push it to stack
        if (!isOperator(postfix[i])) {
            newNode = createNode(postfix[i]);
            push(st, newNode);
        } else { // If character is an operator
            newNode = createNode(postfix[i]);

            // Pop two operands
            t1 = pop(st);
            t2 = pop(st);

            // Make them children of the new operator node
            newNode->right = t1;
            newNode->left = t2;

            // Push the new subtree back to stack
            push(st, newNode);
        }
    }

    Node* root = pop(st);
    free(st);
    return root;
}



void inorderRecursive(Node* root) {
    if (root) {
        inorderRecursive(root->left);
        printf("%c ", root->data);
        inorderRecursive(root->right);
    }
}

void preorderRecursive(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(Node* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%c ", root->data);
    }
}

void inorderNonRecursive(Node* root) {
    if (root == NULL) return;
    Stack* st = createStack();
    Node* current = root;

    while (current != NULL || !isEmpty(st)) {
        // Reach the left most node of the current node
        while (current != NULL) {
            push(st, current);
            current = current->left;
        }
        // Current must be NULL at this point
        current = pop(st);
        printf("%c ", current->data);

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        current = current->right;
    }
    free(st);
}

void preorderNonRecursive(Node* root) {
    if (root == NULL) return;
    Stack* st = createStack();
    push(st, root);

    while (!isEmpty(st)) {
        Node* node = pop(st);
        printf("%c ", node->data);

        // Push right and then left children to the stack
        if (node->right) {
            push(st, node->right);
        }
        if (node->left) {
            push(st, node->left);
        }
    }
    free(st);
}

void postorderNonRecursive(Node* root) {
    if (root == NULL) return;
    Stack* st = createStack();
    Node* current = root;
    Node* lastVisited = NULL;

    while (current != NULL || !isEmpty(st)) {
        if (current != NULL) {
            push(st, current);
            current = current->left;
        } else {
            Node* peekNode = peek(st);
            // If right child exists and traversing node from left child, move right
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                printf("%c ", peekNode->data);
                lastVisited = pop(st);
            }
        }
    }
    free(st);
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    Node* root = constructExpressionTree(postfix);

    printf("\nRecursive Traversals\n");
    printf("In-order:   ");
    inorderRecursive(root);
    printf("\n");

    printf("Pre-order:  ");
    preorderRecursive(root);
    printf("\n");

    printf("Post-order: ");
    postorderRecursive(root);
    printf("\n");

    printf("\nNon-Recursive Traversals\n");
    printf("In-order:   ");
    inorderNonRecursive(root);
    printf("\n");

    printf("Pre-order:  ");
    preorderNonRecursive(root);
    printf("\n");

    printf("Post-order: ");
    postorderNonRecursive(root);
    printf("\n");

    return 0;
}

