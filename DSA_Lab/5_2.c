Linear Singly Circular Linked List with Operations

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};


void insert(struct node *head,int data){
    struct node *p;
    p = head;
    struct node *temp;
    if (p->data == -1){
        p->data = data;
    }else{
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    while (p->next != head){
        p = p->next;
    }
    p->next = temp;
    }
}

void insertatbegin(struct node **head,int data){
    struct node *p;
    p = *head;
    struct node *temp;
    if (p->data == -1){
        p->data = data;
    }else{
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = *head;
        while (p->next != *head){
            p = p->next;
        }
        p->next = temp;
        *head = temp;
}}

void display(struct node *head){
    struct node *p;
    p= head;
    while (p->next != head){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

void deleteatbegin(struct node **head){
    struct node *p;
    p = *head;
    if (p->data == -1){
        printf("Empty");
    }
    else{
        if (p->next == *head){
            p->data = -1;
        }else{
            struct node *temp;
            temp = p->next;
            while (p->next != *head){
            p = p->next;
            }
            p->next = temp;
            *head = temp;
            }
        
    }
}

void deleteatend(struct node *head){
    struct node *pointer,*prev;
    pointer =head;
    prev = head;
    if (pointer->data == -1){
        printf("No element found");
    }else{
        if(pointer->next != head){
            pointer = pointer->next;
        }
        else{
            pointer->data = -1;
        }
    }
    while (pointer->next != head){
        pointer=pointer->next;
        prev = prev->next;
    }
    
    prev->next = head;
}

int main(){
    struct node *head;
    struct node *p;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = -1;
    head->next = head;
    p = head;
    int val,choice;
     bool a = true;
     
    while (a){
        printf("Link list menu:\n1.Insert at begining\n2.Insert at end:\n3.Delete at begin\n4.Delete at last\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element: ");
            scanf("%d",&val);
            insertatbegin(&head,val);
            break;
            case 2:
            printf("Enter the element: ");
            scanf("%d",&val);
            insert(head,val);
            break;
            case 3:
            deleteatbegin(&head);
            break;
            case 4:
            deleteatend(head);
            break;
            case 5:
            display(head);
            break;
            case 6:
            a = false;
            break;
            default:
            printf("Invalid option");
            break;
        }
    }
    
    insert(head,5);
    display(head);
    insertatbegin(&head,9);
    display(head);
    deleteatend(head);
    display(head);
    return 0;
}

