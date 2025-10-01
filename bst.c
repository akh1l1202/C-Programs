#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Global root
struct Node* root = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Helper to find minimum node (used in deletion)
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Recursive insert using global root
void insertNode(struct Node** node, int value) {
    if (*node == NULL) {
        *node = createNode(value);
        return;
    }
    if (value < (*node)->data)
        insertNode(&((*node)->left), value);
    else if (value > (*node)->data)
        insertNode(&((*node)->right), value);
}

// Recursive delete using global root
void deleteNode(struct Node** node, int value) {
    if (*node == NULL) return;

    if (value < (*node)->data) {
        deleteNode(&((*node)->left), value);
    }
    else if (value > (*node)->data) {
        deleteNode(&((*node)->right), value);
    }
    else {
        // Case 1: No child or one child
        if ((*node)->left == NULL) {
            struct Node* temp = (*node)->right;
            free(*node);
            *node = temp;
        }
        else if ((*node)->right == NULL) {
            struct Node* temp = (*node)->left;
            free(*node);
            *node = temp;
        }
        else {
            // Case 2: Two children
            struct Node* temp = findMin((*node)->right);
            (*node)->data = temp->data;
            deleteNode(&((*node)->right), temp->data);
        }
    }
}

// Recursive search
void searchNode(struct Node* node, int value) {
    if (node == NULL) {
        printf("%d not found\n", value);
        return;
    }
    if (node->data == value) {
        printf("%d found in BST\n", value);
        return;
    }
    if (value < node->data)
        searchNode(node->left, value);
    else
        searchNode(node->right, value);
}

// Traversals
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

// Main Function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree (Global + Void) ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertNode(&root, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                deleteNode(&root, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                searchNode(root, value);
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
