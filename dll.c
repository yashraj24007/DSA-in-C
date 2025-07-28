#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *prevlink;
    int data;
    struct node *nxtlink;
} *start = NULL, *curr = NULL;
void create() 
{
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    nn->data = d;
    nn->prevlink = NULL;
    nn->nxtlink = NULL;
    if (start == NULL) 
	{
        start = nn;
        curr = nn;
    } else 
	{
        curr->nxtlink = nn;
        nn->prevlink = curr;
        curr = nn;
    }
}

void displayf() 
{
    struct node *temp = start;
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->nxtlink;
    }
}

void displayb() 
{
    struct node *temp = curr;
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->prevlink;
    }
}

void insertatbegin() 
{
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data: ");
    scanf("%d", &d);
    nn->data = d;
    nn->prevlink = NULL;
    nn->nxtlink = start;
    if (start != NULL) 
        start->prevlink = nn;
    else
        curr = nn;
    start = nn;
}

void insertatend() 
{
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data: ");
    scanf("%d", &d);
    nn->data = d;
    nn->nxtlink = NULL;
    if (start == NULL) 
	{
        nn->prevlink = NULL;
        start = nn;
        curr = nn;
    } 
	else 
	{
        curr->nxtlink = nn;
        nn->prevlink = curr;
        curr = nn;
    }
}

void delatbegin() 
{
    if (start == NULL) 
		return;
    struct node *temp = start;
    start = start->nxtlink;
    if (start != NULL)
        start->prevlink = NULL;
    else
        curr = NULL;
    free(temp);
}

void delatend() 
{
    if (curr == NULL) 
		return;
    struct node *temp = curr;
    curr = curr->prevlink;
    if (curr != NULL)
        curr->nxtlink = NULL;
    else
        start = NULL;
    free(temp);
}

void insertatpos() 
{
    struct node *temp = start, *nn = (struct node*)malloc(sizeof(struct node));
    int d, p, i = 1;
    printf("\nEnter the data and position respectively: ");
    scanf("%d%d", &d, &p);
    nn->data = d;
    if (p == 1) 
	{
        insertatbegin();
        return;
    }
    while (temp != NULL && i < p - 1) 
	{
        temp = temp->nxtlink;
        i++;
    }
    if (temp == NULL || temp->nxtlink == NULL) 
	{
        insertatend();
        return;
    }
    nn->nxtlink = temp->nxtlink;
    nn->prevlink = temp;
    temp->nxtlink->prevlink = nn;
    temp->nxtlink = nn;
}

void delatpos() 
{
    struct node *temp = start;
    int p, i = 1;
    printf("\nEnter position to delete: ");
    scanf("%d", &p);
    if (start == NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    if (p == 1) 
	{
        delatbegin();
        return;
    }
    
    while (temp != NULL && i < p) 
	{
        temp = temp->nxtlink;
        i++;
    }
    
    if (temp == NULL) 
	{
        printf("Invalid position.\n");
        return;
    }
    if (temp->nxtlink != NULL)
        temp->nxtlink->prevlink = temp->prevlink;
    if (temp->prevlink != NULL)
        temp->prevlink->nxtlink = temp->nxtlink;
    if (temp == curr)
        curr = temp->prevlink;
    free(temp);
}

int main() {
    create();
    create();
    create();
    displayf();
    printf("\n");
    displayb();
    insertatbegin();
    displayf();
    insertatend();
    displayf();
    insertatpos();
    printf("\n");
    displayf();
    delatbegin();
    printf("\n");
    displayf();
    delatend();
    printf("\n");
    displayf();
    delatpos();
    printf("\n");
    displayf();
}

