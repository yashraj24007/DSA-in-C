#include<stdio.h>

void heapsort(int arr[],int n);
void heapify(int arr[],int n,int i);
void swap(int *a,int *b);

void heapsort(int arr[],int n)
{
  int i;
  //constructing max heap
  for(i=(n/2-1);i>=0;i--)
  	heapify(arr,n,i);
  	
  for(i=n-1;i>=0;i--)
  {
    swap(&arr[0],&arr[i]);
    heapify(arr,i,0);
  }
}

void heapify(int arr[],int n,int i){
  int large=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n && arr[left] > arr[large])
  large=left;
  if(right<n && arr[right] > arr[large])
  large=right;
  if(large!=i)
  {
    swap(&arr[i],&arr[large]);
    heapify(arr,n,large);
  }
}

void swap(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void main()
{
  int n;
  printf("Enter the size of array: ");
  scanf("%d",&n);
  int arr[n],i;
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  heapsort(arr,n);
  printf("Array after sorting: ");
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
}
