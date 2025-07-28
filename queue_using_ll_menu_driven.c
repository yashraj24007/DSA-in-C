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
void peek()
{
	struct queue *temp=rear;
	printf("%d is the topmost data",temp->data);
}
int main()
{
	int ch;
	while(1)
	{
	printf("Enter Your Choice\n1. Enque\n2. Dequeue\n3. Display\n 4. Peek 5. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: 
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3: 
			display();
			break;
		case 4:
			peek();
			break;
		case 5:
			exit(0);
	}
    }
}
