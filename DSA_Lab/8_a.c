#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int x) {
    if (rear >= (MAX - 1)) {
        printf("Queue Overflow\n");
    } else {
        queue[++rear] = x;
        printf("%d enqueued into queue\n", x);
    }
}

int dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return 0;
    } else {
        int x = queue[front++];
        return x;
    }
}

void printQueue() {
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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
