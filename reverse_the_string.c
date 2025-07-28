#include<stdio.h>
#include<stdlib.h>
char s[20];
int top=-1;
void push(char d)
{
    s[++top]=d;
}
char pop()
{
    return s[top--];
}
int main()
{
    char exp[19];
    int i;
    printf("Enter the String: ");
    scanf("%s",&exp);
    for(i=0;exp[i]!='\0';i++)
    {
        push(exp[i]);
    }
    for(i=0;exp[i]!='\0';i++)
    {
       printf(" %c ",pop(exp[i]));
    }
    
}

