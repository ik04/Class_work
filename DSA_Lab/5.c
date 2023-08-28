#include <stdio.h>
#include <stdlib.h>

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
    temp->next = NULL;
    while (p->next != NULL){
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
        *head = temp;
    }
}


void display(struct node *head){
    struct node *p;
    p= head;
    while (p->next != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

void deleteatend(struct node *head){
    struct node *pointer,*prev;
    pointer =head;
    prev = head;
    if (pointer->data == -1){
        printf("No element found");
    }else{
        if(pointer->next != NULL){
            pointer = pointer->next;
        }
        else{
            pointer->data = -1;
        }
    }
    while (pointer->next != NULL){
        pointer=pointer->next;
        prev = prev->next;
    }
    
    prev->next = NULL;
}

void deleteatbegin(struct node **head){
    struct node *p;
    p = *head;
    if (p->data == -1){
        printf("Empty");
    }
    else{
        if (p->next == NULL){
            p->data = -1;
        }else{
            struct node *temp;
            temp = p->next;
            *head = temp;
        }
        
    }
}

void deleteElement(struct node** head, int data) {
    struct node* current = *head;
    struct node* previous = NULL;

    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (current->data == data) {
        *head = current->next;
        free(current);
        printf("Element %d deleted.\n", data);
        return;
    }

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    previous->next = current->next;
    free(current);
    printf("Element %d deleted.\n", data);
}



int main() {
    struct node *head;
    struct node *p;

    head = (struct node *)malloc(sizeof(struct node));

    head->data = -1;
    head->next = NULL;
    p = head;

    int choice;
    int data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete at the beginning\n");
        printf("4. Delete at the end\n");
        printf("5. Delete specific element\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertatbegin(&head, data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insert(head, data);
                break;

            case 3:
                deleteatbegin(&head);
                break;

            case 4:
                deleteatend(head);
                break;
                
            case 5:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteElement(&head, data);
                break;

            case 6:
                display(head);
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
