#include <stdio.h>
#include <stdlib.h>
struct queue 
{
    int data;
    struct queue *link;
}*front = NULL, *rear = NULL;
void enqueue() 
{
    struct queue *n = (struct queue*)malloc(sizeof(struct queue));
    int d;
    printf("Enter element to enqueue: ");
    scanf("%d", &d);
    n->data = d;
    n->link = NULL;
    if (front == NULL) 
	{
        front = rear = n; 
    } 
	else 
	{
        rear->link = n; 
        rear = n;       
    }
}
void dequeue() 
{
    struct queue *temp = front;
    front = front->link;
    free(temp);
}
void display() 
{
    struct queue *temp = front;
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main() 
{
    enqueue();
    enqueue();
    enqueue();
    display(); 
    dequeue();
    display();
}

