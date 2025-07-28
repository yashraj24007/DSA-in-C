#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *link;
}*top=NULL;
void push()
{
	struct stack *n=(struct stack*)malloc(sizeof(struct stack));
	int d;
	printf("Enter the data to Push: ");
	scanf("%d",&d);
	n->data=d;
	n->link=top;
	top=n;
}
void peek()
{
	struct stack *temp=top;
	printf("Peeked Element is %d \n",temp->data);
}
void pop()
{
	struct stack *temp=top;
	top=top->link;
	free(temp);
}
void display()
{
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->link;
	}
}
int main()
{
	push();
	push();
	push();
	pop();
	peek();
	display();
}
