#include<stdio.h>
#include<ctype.h>
char st[20];
int top=-1;
void push(char ch)
{
  st[++top]=ch;
}
int pop()
{
  return st[top--];
}
int priority(char ch)
{
  if(ch=='(')
  return 0;
  if(ch=='+'||ch=='-')
  return 1;
  if(ch=='*'||ch=='/')
  return 2;
  if(ch=='^')
  return 3;
}
void main()
{
  int i;
  char expr[20],x;
  printf("enter the infix expression");
  scanf("%s",expr);
  for(i=0;expr[i]!='\0';i++)
  {
    if(isalpha(expr[i]))
      printf("%c",expr[i]);
    else if(expr[i]=='(')
      push(expr[i]);
    else if(expr[i]==')')
    {
      while((x=pop())!='(')
      printf("%c",x);
    }
    else
    {
      while(priority(st[top])>=priority(expr[i]))
    	{
        	printf("%c",pop());
    	}
      push(expr[i]);
    }
  }
  while(top!=-1)
    printf("%c",pop());
}
