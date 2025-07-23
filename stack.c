#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;
// create push pop peek display destroy


void push() {
    if (top == SIZE-1) {
        printf("Stack is full.\n");
    }
    else {
        int num;
        printf("Enter element to push: ");
        scanf("%d",&num);
        stack[top+1] = num;
        top++;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Popped element: %d\n",stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("The top element is: %d\n",stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Current stack\n");
        int i;
        for (i=top; i >= 0; i--) {
            printf("%d\n",stack[i]);
        }
    }
}

void destroy() {
    if (top == -1) {
        printf("Stack is already empty.\n");
    }
    else {
        top = -1;
        printf("Stack destroyed.\n");
    }
}

int main() {

    int choice;
    while (1) {

        printf("\nMenu for stack operations \n\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Destroy\n6. Exit\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            push();
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
            printf("Entered wrong choice.\n");
        }
    }

    return 0;


}
