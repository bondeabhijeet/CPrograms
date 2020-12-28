#include<stdio.h>
int facto(int);
void main()
{
    int n, c;
    scanf("%d", &n);
    c=facto(n);
    printf("%d", c);
}
int facto(int n)
{

    if(n<=1)
    {
        return(1);
    }
    else
    {
        return(n*(facto(n-1)));
    }

}
