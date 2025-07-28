#include <stdio.h>
#include <ctype.h>
#include <math.h>
int st[20];
int top = -1;
void push(int x) 
{
    st[++top] = x;
}
int pop() 
{
    return st[top--];
}
int main()
{
    char expr[20];
    int op1, op2;
    printf("Enter the postfix expression: ");
    scanf("%s", expr);  
    for (int l = 0; expr[l] != '\0'; l++) 
	{
        if (isdigit(expr[l])) 
		{
            push(expr[l] - '0'); 
        } 
		else 
		{
            op1 = pop();
            op2 = pop();
            switch (expr[l])
			{
                case '+':
                    push(op2 + op1);
                    break;
                case '-':
                    push(op2 - op1);
                    break;
                case '*':
                    push(op2 * op1);
                    break;
                case '/':
                    push(op2 / op1);
                    break;
                case '^':
                    push((int)pow(op2, op1)); 
                    break;
            }
        }
    }
    if (top != 0) 
	{
        printf("Error: Too many operands!\n");
        return 1;
    }
    printf("\nResult = %d\n", pop()); 
}

