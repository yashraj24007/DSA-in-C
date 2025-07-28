#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
  struct node *left;
  char data;
  struct node *right;
}*stack[30];

int top=-1;

void push(struct node *c){
  stack[++top]=c;
}

struct node *pop(){
  return stack[top--];
}

void Inorder(struct node *temp){
  if(temp!=NULL){
    Inorder(temp->left);
    printf("%c",temp->data);
    Inorder(temp->right);
  }
}

void main()
{
  char exp[20];
  printf("Enter the postix Expression: ");
  scanf("%s",exp);
  int i;
  for(i=0;exp[i]!='\0';i++)
  {
    if(isalpha(exp[i]))
	{
      struct node *newnode;
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->left=NULL;
      newnode->data=exp[i];
      newnode->right=NULL;
      push(newnode);
    }
    else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
	{
      struct node *ptr1,*ptr2;
      ptr1=pop();
      ptr2=pop();
      struct node *newnode;
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=exp[i];
      newnode->right=ptr1;
      newnode->left=ptr2;
      push(newnode);
    }
  }
  Inorder(stack[0]);
}
