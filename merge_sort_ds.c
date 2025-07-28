#include<stdio.h>
void merge(int [],int,int,int);
void mergesort(int a[],int si,int ei)
{
	if(si<ei)
	{
int mi;
mi=(si+ei)/2;
mergesort(a,si,mi);
mergesort(a,mi+1,ei);
merge(a,si,mi,ei);
}
}
void merge(int a[],int si,int mi,int ei)
{
  int b[ei+1];
  int i=si;
  int j=mi+1;
  int k=0;
  while(i<=mi&&j<=ei)
  {
    if(a[i]<a[j])
    {
      b[k]=a[i];
      i++;
      k++;
    }
    else
    {
      b[k]=a[j];
      k++;
      j++;
    }
  }	
  while(i<=mi)
  {
    b[k]=a[i];
    i++;
    k++;
  }
  while(j<=ei)
  {
    b[k]=a[j];
    j++;
    k++;
  }
  for(i=si,k=0;i<=ei;i++,k++)
  {
    a[i]=b[k];
  }
}  
int main()
{
  int i,n;
  printf("enter size of the array:  ");
  scanf("%d",&n);
  int a[n];
  printf("\nEnter Elements of the array: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  mergesort(a,0,n-1);
  printf("\nsorted array: ");
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  
}

