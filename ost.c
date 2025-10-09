#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct node {
    int data;
    struct node* next;
};

int i;

struct node* start = NULL; // Initializing the linked list as empty

// Function to insert a node at the end
void insertEnd(int num) {
    struct node* newnode, *temp;
    newnode = malloc(sizeof(struct node));

    // Check if malloc succeeded
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = num;
    newnode->next = NULL;

    if (start == NULL) {
        printf("Linked list is empty. Adding the first element.\n");
        start = newnode; // If list is empty, make the new node the start
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newnode; // Insert the new node at the end
        printf("%d inserted at the end of the linked list.\n", num);
    }
}

// Function to insert a node at a specific position
void insert(int position, int num) {
    struct node* newnode, *temp;
    newnode = malloc(sizeof(struct node));

    // Check if malloc succeeded
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = num;
    newnode->next = NULL;

    if (position == 1) {
        newnode->next = start;
        start = newnode; // Insert at the start
        printf("%d inserted at start.\n", num);
    } else {
        if (start == NULL) { // If the list is empty
            printf("Linked list is empty, inserting at position 1 instead.\n");
            start = newnode; // Make it the first element
        } else {
            temp = start;
            for (i = 1; i < position - 1 && temp != NULL; i++) {
                temp = temp->next; // Traverse to one node before the specified position
            }

            if (temp == NULL) {
                printf("Position is out of bounds.\n");
                free(newnode); // Free the memory if insertion fails
                return;
            } else {
                newnode->next = temp->next; // Point to the next node
                temp->next = newnode; // Insert the new node
                printf("%d inserted at position %d in the linked list.\n", num, position);
            }
        }
    }
}

// Function to delete the start node of the linked list
void delete() {
    struct node* temp;

    if (start == NULL) { // If the list is empty
        printf("Linked list is empty.\n");
        return;
    } else {
        temp = start;
        start = start->next; // Move start to the next node
        free(temp); // Free the memory of the old start node
        printf("Start node deleted.\n");
    }
}

// Function to display the linked list
void display() {
    struct node* temp = start;

    if (temp == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("The elements in the linked list are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, n, p;

    do {
        printf("\n\nMENU FOR OPERATIONS\n\n");
        printf("1. Insert at end\n");
        printf("2. Insert at a position\n");
        printf("3. Delete start node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to insert at end: ");
                if (scanf("%d", &n) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                insertEnd(n);
                break;

            case 2:
                printf("Enter element to be inserted: ");
                if (scanf("%d", &n) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                printf("Enter position: ");
                if (scanf("%d", &p) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                insert(p, n);
                break;

            case 3:
                delete();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0); // Exit the program
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5); // Loop until the user chooses to exit

    return 0;
}
