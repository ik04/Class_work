#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return 0;
    }

    Node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }

    int x = temp->data;
    free(temp);

    return x;
}

void printQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        Node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Dequeued value: %d\n", dequeue());
                break;
            case 3:
                printQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
