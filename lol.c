#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head=NULL;

void create(int value) {
    struct node* head=create(value);
    head->next=head;
}
void insert(int value) {
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;

    if (head==NULL) {
        head=temp;
        temp->next=head;
        return;
    }
    if (value < head->data) {
        struct node* last=head;
        while (last->next !=head) {
            last=last->next;
        }
        last->next=temp;
        temp->next=head;
        head=temp;
        return;
    }
    struct node* q=head;
    while (q->next!=head && q->next->data < value) {
        q=q->next;
    }
    temp->next=q->next;
    q->next=temp;
}

void display() {
    if (head==NULL) {
        printf("list is empty\n");
        return;
    }
    struct node* q=head;
    do {
        printf("%d -> ",q->data);
        q=q->next;
    } while (q!=head);
    printf("(back to head)\n");
}

void deletenode(int value) {
    if (head==NULL) {
        printf("list is empty");
        return;
    }
    struct node* temp=head;
    struct node* prev=NULL;
    if (head->next==head) {
        if (head->data==value) {
            free(head);
            head=NULL;
            printf("Deleted %d",value);
        } else {
            printf("Value %d not found",value);
        }
        return;
    }
    if (head->data==value) {
        struct node* last=head;
        while (last->next!=head) {
            last=last->next;
        }
        struct node* del=head;
        last->next = head->next;
        head = head->next;
        free(del);
        printf("Deleted %d",value);
        return;
    }
    while (temp->next != head && temp->next->data != value) {
        temp=temp->next;
    }

    if (temp->next->data==value) {
        struct node* del=temp->next;
        temp->next=del->next;
        free(del);
        printf("Deleted %d",value);
    } else {
        printf("Value %d not found",value);
    }
}
