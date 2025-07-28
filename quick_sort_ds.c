#include<stdio.h>
int partition(int a[],int l,int h);
void quicksort(int a[], int l, int h) 
{
    if (l < h) 
	{
        int loc = partition(a, l, h);
        quicksort(a, l, loc - 1);
        quicksort(a, loc + 1, h);
    }
}
int partition(int a[], int l, int h)
{
    int pivot = l, i = l, j = h, temp;
    while (i < j) 
	{
        while (i < h && a[i] <= a[pivot]) 
		{
            i++;
        }
        while (j > l && a[j] > a[pivot]) 
		{
            j--;
        }
        if (i < j) 
		{
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;
    return j;
}
int main() 
{
    int n, i;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter Elements: ");
    for (i = 0; i < n; i++) 
{
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);
    }
}

