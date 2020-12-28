#include<stdio.h>
#include<math.h>
void main()
{
int n, p, z, count;
double sum;
printf("Enter the number:");
scanf("%d", &n);
z=n;
count=0;
while(n!=0)
{
    //p=n%10;
    n=n/10;
    ++count;
}
n=z;
sum=0.00;
while(n!=0)
{
    p=n%10;
    n=n/10;

    sum = sum + pow((double)(p), (double)(count));

}
n=z;
printf("%lf", sum);
if(sum==(double)n)
{
    printf("\nARMSTRONG NUMBER\n");
}
else
{
    printf("\nNOT A ARMSTRONG NUMBER\n");
}

}
