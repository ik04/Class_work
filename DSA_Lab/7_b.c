#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        Node* temp = top;
        int x = temp->data;
        top = top->next;
        free(temp);
        return x;
    }
}

void printStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        Node* temp = top;
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
        printf("\n1. Push\n2. Pop\n3. Print\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf("Popped value: %d\n", pop());
                break;
            case 3:
                printStack();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
