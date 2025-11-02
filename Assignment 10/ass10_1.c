#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    char items[MAX];
    int top;
};


void initStack(struct Stack *s) {
    s->top = -1;
}


int isEmpty(struct Stack *s) {
    return s->top == -1;
}


void push(struct Stack *s, char c) {
    if (s->top == MAX - 1)
        printf("Stack overflow\n");
    else
        s->items[++(s->top)] = c;
}


char pop(struct Stack *s) {
    if (isEmpty(s))
        return '\0';  // Empty stack
    else
        return s->items[(s->top)--];
}


int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


int isBalanced(char *expr) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s))
                return 0;
            char top = pop(&s);
            if (!isMatchingPair(top, c))
                return 0;
        }
    }

    return isEmpty(&s);
}

// Main function
int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("Balanced parentheses\n");
    else
        printf("Not balanced\n");

    return 0;
}
