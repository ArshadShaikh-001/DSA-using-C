#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;



Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inserts a new value into the BST
Node* insert(Node* node, int value) {
    // If the tree is empty, create a new node
    if (node == NULL) {
        return createNode(value);
    }
    // Otherwise, recur down the tree
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

// Finds the smallest node in a subtree (inorder successor)
Node* findMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    // Find the node
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Case 1 & 2 Node with one or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3 Node with two children
        Node* temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Searches for a value in the BST
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}



void displayInorder(Node* root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

void displayPreorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayPostorder(Node* root) {
    if (root != NULL) {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d ", root->data);
    }
}

// Calculates the depth of the tree
int depth(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // return the larger depth + 1
        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

void displayParents(Node* root) {
    if (root != NULL) {
        // A node is a parent if it has at least one child
        if (root->left != NULL || root->right != NULL) {
            printf("Parent: %d | ", root->data);
            if (root->left) printf("Left Child: %d ", root->left->data);
            if (root->right) printf("Right Child: %d", root->right->data);
            printf("\n");
        }
        displayParents(root->left);
        displayParents(root->right);
    }
}


void displayLeaves(Node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        }
        displayLeaves(root->left);
        displayLeaves(root->right);
    }
}

// Helper function to print nodes at a given level
void printGivenLevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void displayLevelOrder(Node* root) {
    int h = depth(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    while(1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Display tree (Inorder, Preorder, Postorder)\n");
        printf("5. Display depth of the tree\n");
        printf("6. Display parent nodes with children\n");
        printf("7. Display leaf nodes\n");
        printf("8. Display tree level-wise\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the tree.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                   root = deleteNode(root, value);
                   printf("%d deleted from the tree.\n", value);
                } else {
                   printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder traversal: ");
                    displayInorder(root);
                    printf("\n");
                    printf("Preorder traversal: ");
                    displayPreorder(root);
                    printf("\n");
                    printf("Postorder traversal: ");
                    displayPostorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Depth of the tree is: %d\n", depth(root));
                break;
            case 6:
                 if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Parent nodes and their children:\n");
                    displayParents(root);
                }
                break;
            case 7:
                 if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Leaf nodes: ");
                    displayLeaves(root);
                    printf("\n");
                }
                break;
            case 8:
                 if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Level-wise traversal: ");
                    displayLevelOrder(root);
                    printf("\n");
                }
                break;
            case 0:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
