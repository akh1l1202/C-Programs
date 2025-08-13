
//create delete insert display search

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int i;

struct node* start=NULL;

void create() {
    struct node *newnode,*temp;
    int n,data;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for (i=0; i<n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;

        if (start==NULL) {
            start=newnode;
        } else {
            temp=start;
            while (temp->next != NULL) {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void insert(int p,int val) {
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if (p==1) {
        newnode->next=start;
        start=newnode;
    }
    temp=start;
    for (i=1; temp!=NULL && i<p-1; i++) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Position doesnt exist.");
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}


void display() {
    struct node *temp=start;

    if (temp==NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    while (temp!=NULL) {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void delete(int p) {
    struct node *temp=start,*nextNode;

    if (start==NULL) {
        printf("Nothing to delete.");
        return;
    }

    if (p==1) {
        start=start->next;
        free(temp);
        printf("Node at position 1 deleted.");
        return;
    }

    for (i=1; temp!=NULL && i<p-1; i++) {
        temp=temp->next;
    }

    if (temp==NULL || temp->next==NULL) {
        printf("Position doesnt exist.");
        return;
    }

    nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;

    printf("Node at position %d deleted.\n", p);
}
void search(int val) {
    struct node *temp=start;
    int p=1;
    while (temp!=NULL) {
        if (temp->data == val) {
            printf("found at position %d.",p);
            return;
        }
        temp=temp->next;
        p++;
    }
    printf("Value %d not found in the list.\n", val);
}
int main() {
    int choice,p,val;

    while (1) {
        printf("\nMenu:\n1. Create list\n2. Insert\n3. Delete\n 4. Search\n5. Display\n6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            create();
            break;
        case 2:
            printf("Enter position to insert: ");
            scanf("%d",&p);
            printf("Enter value to insert: ");
            scanf("%d",&val);
            insert(p,val);
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &p);
            delete(p);
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d",&val);
            search(val);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.");
        }
    }

    return 0;
}
