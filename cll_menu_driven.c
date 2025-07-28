#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*start=NULL,*curr;
void create(int ele)
{
  struct node *nn;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->data=ele;
  if(start==NULL)
  {
    start=nn;
    nn->next=start;
  }
  else
  {
    curr->next=nn;
    nn->next=start;
  }
  curr=nn;
}

void display()
{
  struct node *temp=start;
  do
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
  while(temp!=start);
}

void insert_at_begin(int ele)
{
  struct node *nn;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->data=ele;
  nn->next=start;
  start=nn;
  curr->next=start;
}

void insert_at_end(int ele)
{
  struct node *nn;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->data=ele;
  curr->next=nn;
  curr=nn;
  curr->next=start;  
}

void delet_at_begin()
{
  struct node *temp;
  temp=start;
  start=start->next;
  curr->next=start;
  free(temp);  
}

void delet_at_end()
{
  struct node *temp=start,*prev;
  while(temp->next!=start)
  {
    prev=temp;
    temp=temp->next;
  }
  curr=prev;
  curr->next=start;
  free(temp);
}

void insert_by_position(int ele,int pos)
{
  struct node *temp,*prev;
  temp=start;
  struct node *nn;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->data=ele;
  int i=1;
  if(pos==1)
    insert_at_begin(ele);
  else{
    do{
      if(i==pos)
	  {
        break;
      }
      else
	  {
        prev=temp;
        temp=temp->next;
        i++;
      }
    }
	while(temp->next!=start);
    prev->next=nn;
    nn->next=temp;
  }
}

void delet_by_position(int pos)
{
  struct node *temp=start,*prev;
  int i=1;
  while(temp->next!=start)
  {
    if(i==pos)
      break;
    else
    {
      prev=temp;
      temp=temp->next;
      i++;
    }
  }
  prev->next=temp->next;
  free(temp);
}

void search(int ele)
{
  struct node *temp;
  temp=start;
  int i=1,c=0;
  do{
    if(temp->data==ele)
    {
      c=1;
      break;
    }
    else{
      i++;
      temp=temp->next;
    }
  }
  while(temp!=start);
  if(c==0)
    printf("%d is not present in the LL\n",ele);
  else
    printf("%d found at %d position and %d index\n",ele,i,i-1);
}

void max()
{
  int max=0;
  if(start ==NULL)
    printf("SINGLY CIRCULAR LINKED LIST is Empty\n");
  struct node *temp;
  temp=start;
  do
  {
    if(temp->data > max)
      max=temp->data;
    temp=temp->next;
  }
  while(temp!=start);
  printf("Maximum element in the LL is :%d\n",max);
}

void min()
{
  if(start ==NULL)
    printf("SINGLY CIRCULAR LINKED LIST is Empty\n");
  struct node *temp;
  temp=start;
  int min=temp->data;
  do
  {
    if(temp->data < min)
      min=temp->data;
    temp=temp->next;
  }
  while(temp!=start);
  printf("Minimum element in the LL is :%d\n",min);
}

void count()
{
  if(start==NULL)
    printf("SINGLY CIRCULAR LINKED LIST is Empty\n");
  struct node *temp;
  temp=start;
  int c=0;
  do
  {
    c++;
    temp=temp->next;
  }while(temp!=start);
  printf("No.of nodes in the LL is:%d\n",c);
}

void reverse()
{
  struct node *prev=curr,*temp=start,*next=curr;
  do{
    next=temp->next;
    temp->next=prev;
    prev=temp;
    temp=next;
  }
  while(temp!=start);
  start=prev;
}

void sort()
{
  struct node *temp=start,*temp1=start;
  int x;  
  do{
    do
	{
      if(temp1->data > temp1->next->data){
        x=temp1->data;
        temp1->data=temp1->next->data;
        temp1->next->data=x;
      }
      temp1=temp1->next;
    }while(temp1->next!=start);
    temp=temp->next;
    temp1=start;
  }while(temp!=start);
}

void insert_after(int key,int data){
  struct node *nn,*temp=start;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->data=data;
  do{
    if(temp->data==key){
      break;
    }
    else{
      temp=temp->next;
    }
  }while(temp!=start);
  nn->next=temp->next;
  temp->next=nn;
}

void delet_by_key(int key){
  struct node *temp=start,*prev;
  do{
    if(temp->data == key)
      break;
    else{
      prev=temp;
      temp=temp->next;
    }
  }while(temp!=start);
  prev->next=temp->next;
  free(temp);
}

int main()
{
  int ele,cont,choice,pos,key;
  do{
    printf("1.create a node\n2.display\n3.insert at begin\n4.insert at end\n5.insert by position\n6.delete at begin\n7.delete at end\n8.delete by position\n9.search an element\n10.maximum element\n11.Minimum element\n12.count of nodes\n13.sort the elements\n14.insert after\n15.delete by key\n16.reverse\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the element: ");
        scanf("%d",&ele);
        create(ele);
        break;
      case 2:
        display();
        break;
      case 3:
        printf("Enter the element: ");
        scanf("%d",&ele);
        insert_at_begin(ele);
        break;
      case 4:
        printf("Enter the element: ");
        scanf("%d",&ele);
        insert_at_end(ele);
        break;
      case 5:
        printf("Enter the element: ");
        scanf("%d",&ele);
        printf("Enter the position of the element to be inserted at: ");
        scanf("%d",&pos);
        if(pos==1)
          insert_at_begin(ele);
        else
          insert_by_position(ele,pos);
        break;
      case 6:
        delet_at_begin();
        break;
      case 7:
        delet_at_end();
        break;
      case 8:
        printf("Enter the position: ");
        scanf("%d",&pos);
        delet_by_position(pos);
        break;
      case 9:
        printf("Enter the element to be searched: ");
        scanf("%d",&ele);
        search(ele);
        break;
      case 10:
        max();
        break;
      case 11:
        min();
        break;
      case 12:
        count();
        break;
      case 13:
        sort();
        break;
      case 14:
        printf("Enter the key element and element to be inserted: ");
        scanf("%d %d",&key,&ele);
        insert_after(key,ele);
        break;
      case 15:
        printf("Enter the key: ");
        scanf("%d",&key);
        delet_by_key(key);
        break;
      case 16:
        reverse();
        break;
    }
    printf("Enter 1 continue or other number to exit:");
    scanf("%d",&cont);
  }while(cont==1);
}

