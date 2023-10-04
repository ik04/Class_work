#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertHead(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    if (tail == NULL) {
        tail = head;
    }
}

void insertTail(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (tail == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void deleteHead() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }
}

void deleteTail() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    free(tail);
    tail = temp;
    tail->next = NULL;
}

void printList() {
    Node* node = head;

    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("\n1. Insert at head\n2. Insert at tail\n3. Delete from head\n4. Delete from tail\n5. Print\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insertHead(data);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insertTail(data);
                break;
            case 3:
                deleteHead();
                break;
            case 4:
                deleteTail();
                break;
            case 5:
                printList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
