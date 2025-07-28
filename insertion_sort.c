#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array before sorting is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=1;i<n;i++)
    {
        int key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    printf("The array after sorting is: "); 
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }   
}
