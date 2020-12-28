#include<stdio.h>
int add (int arr[],int);
void main()
{
    int x, i, s;
    scanf("%d", &x);
    int arr[x];

    for(i=0; i<x; ++i)
    {
        scanf("%d", &arr[i]);
    }

    s=add(arr, x);
    printf("%d", s);
}
int add (int arr[],int n)
{
    int sum, i;
    sum=0;
    for(i=0; i<n; ++i)
    {
        sum = sum + arr[i];
    }
    return(sum);
}
