#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *start = NULL, *curr = NULL;

void create() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->link = NULL;

    if (start == NULL) {
        start = nn;
        curr = nn;
    } else {
        curr->link = nn;
        curr = nn;
    }
}
void insertatbegin() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->link = start;
    start = nn;
    if (curr == NULL) { // If list was empty, update curr
        curr = nn;
    }
}

void insertatend() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->link = NULL;

    if (start == NULL) { // If list is empty
        start = nn;
        curr = nn;
    } else {
        curr->link = nn;
        curr = nn;
    }
}

void insertatpos() {
    int d, p, i = 1;
    printf("Enter data and position: ");
    scanf("%d %d", &d, &p);
    
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    
    if (p == 1) { // Insert at beginning
        nn->link = start;
        start = nn;
        if (curr == NULL) {
            curr = nn;
        }
        return;
    }

    struct node *temp = start;
    while (temp != NULL && i < p - 1) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position!\n");
        free(nn);
        return;
    }

    nn->link = temp->link;
    temp->link = nn;

    if (temp == curr) {
        curr = nn;
    }
}

void delatbegin() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = start;
    start = start->link;
    free(temp);
    if (start == NULL) { // If list is empty after deletion
        curr = NULL;
    }
}

void delatend() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = start, *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    if (prev != NULL) {
        prev->link = NULL;
        curr = prev;
    } else {
        start = NULL;
        curr = NULL;
    }
    free(temp);
}

void delatpos() {
    int p, i = 1;
    printf("Enter position: ");
    scanf("%d", &p);

    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = start, *prev = NULL;
    if (p == 1) {
        start = start->link;
        free(temp);
        if (start == NULL) {
            curr = NULL;
        }
        return;
    }

    while (temp != NULL && i < p) {
        prev = temp;
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    prev->link = temp->link;
    if (temp == curr) {
        curr = prev;
    }
    free(temp);
}

void display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter Your Choice:\n");
        printf("1. Create\n2. Insert at Begin\n3. Insert at Position\n4. Insert at End\n");
        printf("5. Delete at Begin\n6. Delete at Position\n7. Delete at End\n");
        printf("8. Display\n9. Exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                insertatbegin();
                break;
            case 3:
                insertatpos();
                break;
            case 4:
                insertatend();
                break;
            case 5:
                delatbegin();
                break;
            case 6:
                delatpos();
                break;
            case 7:
                delatend();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

