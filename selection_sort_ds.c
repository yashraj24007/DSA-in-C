#include<stdio.h>
void selectionsort(int a[],int n)
{
	int i,min,k,j,temp;
	for(i=0;i<n;i++)
	{
		min=a[i];
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				k=j;
			}
		}
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}
int main()
{
	int n,i;
	printf("Enter Number of Elements : ");
	scanf("%d",&n);
	printf("Enter Elements:");
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionsort(a,n);
	printf("After Sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
