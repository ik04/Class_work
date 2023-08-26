#include <stdio.h>
#define MAX_SIZE 1000

int tree[MAX_SIZE];

void insert(int data, int index) {
    if(index < MAX_SIZE) {
        tree[index] = data;
    } else {
        printf("Tree is full\n");
    }
}

void printTree() {
    for(int i = 0; i < MAX_SIZE; i++) {
        if(tree[i] != 0) {
            printf("Node at index %d: %d\n", i, tree[i]);
        }
    }
}

int main() {
    int choice, data, index;

    while(1) {
        printf("\n1. Insert\n2. Print\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                printf("Enter the index where it should be inserted (0 for 1st): ");
                scanf("%d", &index);
                insert(data, index);
                break;
            case 2:
                printTree();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
