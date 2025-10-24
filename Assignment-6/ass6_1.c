#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term in descending order of exponent
void insertTerm(Node** poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == exp) {
            temp->next->coeff += coeff; // combine like terms
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Display polynomial
void display(Node* poly) {
    Node* temp = poly;
    if (temp == NULL) {
        printf("0");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    Node *t1 = p1, *t2 = p2;
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp > t2->exp) {
            insertTerm(&result, t1->coeff, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            insertTerm(&result, t2->coeff, t2->exp);
            t2 = t2->next;
        } else {
            insertTerm(&result, t1->coeff + t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1 != NULL) {
        insertTerm(&result, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL) {
        insertTerm(&result, t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return result;
}

// Subtract two polynomials
Node* subtractPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    Node *t1 = p1, *t2 = p2;
    while (t1 != NULL && t2 != NULL) {
        if (t1->exp > t2->exp) {
            insertTerm(&result, t1->coeff, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            insertTerm(&result, -t2->coeff, t2->exp);
            t2 = t2->next;
        } else {
            insertTerm(&result, t1->coeff - t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1 != NULL) {
        insertTerm(&result, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL) {
        insertTerm(&result, -t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return result;
}

// Input polynomial
Node* inputPolynomial() {
    Node* poly = NULL;
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    return poly;
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice;
    
    do {
        printf("\n--- Polynomial Menu ---\n");
        printf("1. Input Polynomials\n");
        printf("2. Display Polynomials\n");
        printf("3. Add Polynomials\n");
        printf("4. Subtract Polynomials\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Polynomial 1:\n");
                poly1 = inputPolynomial();
                printf("Polynomial 2:\n");
                poly2 = inputPolynomial();
                break;
            case 2:
                printf("Polynomial 1: ");
                display(poly1);
                printf("Polynomial 2: ");
                display(poly2);
                break;
            case 3:
                result = addPolynomials(poly1, poly2);
                printf("Sum: ");
                display(result);
                break;
            case 4:
                result = subtractPolynomials(poly1, poly2);
                printf("Difference (Poly1 - Poly2): ");
                display(result);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}
