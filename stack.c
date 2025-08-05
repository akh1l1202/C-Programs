#include <stdio.h>
#include <stdlib.h>
#define size 10

int stack[size];
int top = -1;

void push(int a) {
    if (top == size - 1) {
        printf("Stack is full.\n");
    } else {
        top++;
        stack[top] = a;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty. Nothing to display.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty. Nothing to display.\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void destroy() {
    if (top == -1) {
        printf("Stack is empty / Is not created yet.\n");
    } else {
        top = -1;
        printf("Stack destroyed successfully.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n#################### Menu for Stack Operations ######################### \n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Destroy\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int a;

        switch(choice) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &a);
                push(a);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                destroy();
                break;

            case 6:
                exit(0);

            default:
                printf("Entered incorrect option. Try again.\n");
        }
    }
}
