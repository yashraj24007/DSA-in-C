#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *link;
} *top = NULL;

void push() {
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    int d;
    printf("Enter the data to Push: ");
    scanf("%d", &d);
    n->data = d;
    n->link = top;
    top = n;
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Peeked Element is %d \n", top->data);
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty, cannot pop\n");
    } else {
        struct stack *temp = top;
        top = top->link;
        free(temp);
        printf("Element popped\n");
    }
}

void display() {
    struct stack *temp = top;
    if (top != NULL) {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter Your choice:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}
 
