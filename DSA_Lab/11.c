#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        root = createNode(data);
    }
    else if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void printInorder(Node* temp) {
    if (temp == NULL)
        return;

    printInorder(temp->left);
    printf("%d ", temp->data);
    printInorder(temp->right);
}

int main() {
    Node* root = NULL;
    int choice, data;
    while(1) {
        printf("\n1. Insert\n2. Print\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printInorder(root);
                printf("\nThe root of the tree is: %d\n", root->data);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
