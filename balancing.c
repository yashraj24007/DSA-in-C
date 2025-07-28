#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
char stk[MAX];
int top = -1;
void push(char item) 
{
    if (top == (MAX - 1))
        printf("Stack is Full\n");
    else
        stk[++top] = item;
}
void pop() 
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        top--; 
}
int main() 
{
    char exp[MAX];
    int i;
    printf("\nINPUT THE EXPRESSION: ");
    scanf("%s", exp);
    for (i = 0; i < strlen(exp); i++) 
	{
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') 
		{
            push(exp[i]); 
        } 
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') 
		{
            if (top == -1) 
			{ 
                printf("\nUNBALANCED EXPRESSION\n");
                exit(1);
            }
            if ((exp[i] == ')' && stk[top] == '(') || (exp[i] == ']' && stk[top] == '[') || (exp[i] == '}' && stk[top] == '{')) 
				{
                	pop();
            	} 
            else 
			{	
                printf("\nUNBALANCED EXPRESSION\n");
                exit(1);
            }
        }
    }
    if (top == -1)
        printf("\nBALANCED EXPRESSION\n"); 
    else
        printf("\nUNBALANCED EXPRESSION\n");
}
