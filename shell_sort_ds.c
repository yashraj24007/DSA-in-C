#include<stdio.h>
int main()
{
	int n,i,j,temp,gap;
	printf("Enter number of elements: ");		
	scanf("%d",&n);
	int a[n];		
	printf("Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before:");
	for(i=0;i<n;i++)
	{
	printf("%d  ",a[i]);
	}
	shellsort(a,n);
	printf("After: ");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	}
void shellsort(int a[], int n)
{
	int gap,j,i,temp;
	for(gap=n/2;gap>=1;gap=gap/2)
	{
	for(j=gap;j<n;j++)
	{
	for(i=j-gap;i>=0;i=i-gap)
	{
		if(a[i+gap]>a[i])
		{
			break;
		}
		else
		{
		temp = a[i+gap];
    	a[i+gap]=a[i];
		a[i]=temp;
		}
	}
	}
	}
}
