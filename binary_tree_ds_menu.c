#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

void insert(struct node *temp, struct node *nn);
void inorder(struct node *temp);
void create(int c);

void create(int c) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = c;
    nn->left = NULL;
    nn->right = NULL;
    
    if (root == NULL)
        root = nn;
    else
        insert(root, nn);
}

void insert(struct node *temp, struct node *nn) {
    char ch;
    printf("Enter your choice (L/R) for node %d under parent %d: ", nn->data, temp->data);
    scanf(" %c", &ch);
    
    if (ch == 'L' || ch == 'l') {
        if (temp->left == NULL)
            temp->left = nn;
        else
            insert(temp->left, nn);
    } else if (ch == 'R' || ch == 'r') {
        if (temp->right == NULL)
            temp->right = nn;
        else
            insert(temp->right, nn);
    } else {
        printf("Invalid choice. Try again.\n");
        insert(temp, nn);
    }
}

void inorder(struct node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

int main() {
    int choice, value;
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}

