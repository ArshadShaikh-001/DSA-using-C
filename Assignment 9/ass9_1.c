#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push function
void push(char c) {
    stack[++top] = c;
}

// Pop function
char pop() {
    return stack[top--];
}

// Function to define precedence
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;
    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;   // if operand, add to postfix
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
    }
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[]) {
    int i;
    int stackEval[SIZE], evalTop = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            stackEval[++evalTop] = c - '0';  // push number
        } else {
            int a = stackEval[evalTop--];
            int b = stackEval[evalTop--];
            switch (c) {
                case '+': stackEval[++evalTop] = b + a; break;
                case '-': stackEval[++evalTop] = b - a; break;
                case '*': stackEval[++evalTop] = b * a; break;
                case '/': stackEval[++evalTop] = b / a; break;
            }
        }
    }
    return stackEval[evalTop];
}

// Main Function
int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nPostfix Expression: %s\n", postfix);

    // For numeric expressions only
    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
