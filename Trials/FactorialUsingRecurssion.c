#include<stdio.h>

int facto(int n);

void main()
{
    int i;
    int n;
    n=3;
    printf("%d", facto(n));
}

int facto(int n)
{
    int factorial;
    if(n==0)
    {
        return(1);
    }
    else
    {
        factorial = n*facto(n-1);
        return(factorial);
    }
}
/*int facto(int n)
{
   if(n==0)
   {
       return(1);
   }
   else
   {
       return(n*facto(n-1));
   }

}*/
