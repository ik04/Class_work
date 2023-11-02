#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
void insert(struct node **head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (*head == NULL) {
        *head = temp;  
    } else {
        struct node *current = *head;
        while (1) {
            if (current->data > data) {
                if (current->left == NULL) {
                    current->left = temp;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = temp;
                    break;
                }
                current = current->right;
            }        }    }    }
void delete(struct node **head, int data) {
    struct node *current = *head;
    struct node *parent = NULL;
    while (current != NULL && current->data != data) {
        parent = current;
        if (current->data > data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == NULL) {
        return;
    }
    if (current->left == NULL) {
        if (parent == NULL) {
            *head = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (parent == NULL) {
            *head = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    } else {
        struct node *successor = current->right;
        struct node *successor_parent = current;
        while (successor->left != NULL) {
            successor_parent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (successor_parent->left == successor) {
            successor_parent->left = successor->right;
        } else {
            successor_parent->right = successor->right;
        }
        free(successor);
    }
}void display(struct node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}
int main() {
    struct node *root = NULL;  // Initialize the root of the tree
    int choice;
    int data;
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(&root, data);
                break;
            case 3:
                printf("Binary Search Tree Contents:\n");
                display(root);
                printf("\n");
                break;
            case 4:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
