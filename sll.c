#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start=NULL,*curr=NULL;
void create()
{
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	int x;
	printf("Enter the data: ");
	scanf("%d",&x);
	nn->data=x;
	nn->link=NULL;
	if(start==NULL)
	{
		start=nn;
		curr=nn;
	}
	else
	{
		curr->link=nn;
		curr=nn;
	}
}
void insertatbegin()
{
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	int x;
	printf("Enter the data: ");
	scanf("%d",&x);
	nn->data=x;
	nn->link=start;
	start=nn;
}

void insertatend()
{
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	int x;
	printf("Enter the data: ");
	scanf("%d",&x);
	nn->data=x;
	nn->link=NULL;
	curr->link=nn;
	curr=nn;
}
void delatbegin()
{
		struct node *temp=start;
		start=start->link;
		free(temp);
}
void delatend()
{
	struct node *prev,*temp=start;
	while(temp->link!=NULL)
	{
		prev=temp;
		temp=temp->link;
	}
	curr=prev;
	prev->link=NULL;
	free(temp);
}
void delatpos()
{
	int p;
	struct node *prev,*temp=start;
	printf("\nEnter the position: ");
	scanf("%d",&p);
	int i=1;
	while(temp!=NULL)
	{
		if(i==p)
		{
			break;
		}
		else
		{
			prev=temp;
			temp=temp->link;
			i++;
		}
    }
	prev->link=temp->link;
	free(temp);
}
void display()
{
	struct node *temp=start;
	while(temp!=NULL)
	{
		printf("%d  ", temp->data);
		temp=temp->link;
	}
	printf("\n");
}
void sum()
{
	int sum=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		sum = sum+temp->data;
		temp=temp->link;
	}
	printf("%d",sum);
}
void product()
{
	int product=1;
	struct node *temp=start;
	while(temp!=NULL)
	{
		product = product * temp->data;
		temp=temp->link;
	}
	printf("%d",product);
}
int main()
{
	create();
	create();
	create();
	display();
	insertatbegin();
	display();
	insertatend();
	display();
	printf("Ater delatbegin: ");
	delatbegin();
	display();
	printf("After delatend: ");
	delatend();
	display();
	printf("After delatpos: ");
	delatpos();
	display();
	printf("Sum: ");
	sum();
	printf("Product : ");
	product();
}
