#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Function to reverse a string
void reverse(char exp[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

// Convert Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    char rev[SIZE], postfix[SIZE];
    int i, j = 0;
    char symbol;

    strcpy(rev, infix);
    reverse(rev); // reverse infix

    // Swap '(' with ')' and vice versa
    for (i = 0; rev[i] != '\0'; i++) {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }

    // Convert to postfix (same logic)
    for (i = 0; rev[i] != '\0'; i++) {
        symbol = rev[i];
        if (isalnum(symbol))
            postfix[j++] = symbol;
        else if (symbol == '(')
            push(symbol);
        else if (symbol == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';

    // Reverse postfix to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Evaluate Prefix Expression
int evaluatePrefix(char prefix[]) {
    int stackEval[SIZE];
    int evalTop = -1;
    int i, len = strlen(prefix);

    for (i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isdigit(c)) {
            stackEval[++evalTop] = c - '0';
        } else {
            int a = stackEval[evalTop--];
            int b = stackEval[evalTop--];
            switch (c) {
                case '+': stackEval[++evalTop] = a + b; break;
                case '-': stackEval[++evalTop] = a - b; break;
                case '*': stackEval[++evalTop] = a * b; break;
                case '/': stackEval[++evalTop] = a / b; break;
            }
        }
    }
    return stackEval[evalTop];
}

// Main function
int main() {
    char infix[SIZE], prefix[SIZE];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("\nPrefix Expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
