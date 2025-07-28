#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
} *root = NULL;
void create() 
{
	int n;
	printf("Enter the data : ");
	scanf("%d", &n);
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> left = NULL;
	newnode -> right = NULL;
	newnode -> data = n;
	if(root == NULL) 
	{
		root = newnode;
	}
	else 
	{
		insert(root, newnode);
	}
}
void insert(struct node *temp, struct node *nn) 
{
	char ch;
	printf("Enter your choice : ");
	scanf(" %c",&ch);
	if(ch == 'L' || ch == 'l') 
	{
		if(temp -> left == NULL)
		{
			temp -> left = nn;
		}
		else 
		insert(temp -> left, nn);
	}
	if(ch == 'R' || ch == 'r') 
	{
		if(temp -> right == NULL) 
		{
			temp -> right = nn;
		}
		else 
		insert(temp -> right, nn);
	}
}

void inorder(struct node * temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
	printf("\n");
}

void preorder(struct node * temp)
{
	if(temp != NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
	printf("\n");
}

void postorder(struct node * temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
	printf("\n");
}

void main() {
	create();
	create();
	create();
	inorder(root);
	preorder(root);
	postorder(root);
}
