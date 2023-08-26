#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if (top >= (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
        printf("%d pushed into stack\n", x);
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        int x = stack[top--];
        return x;
    }
}

void printStack() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
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
