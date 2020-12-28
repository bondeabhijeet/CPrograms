#include<stdio.h>
float facto(int );
void main()
{
    int n, j, i, fact;
    float c;
    scanf("%d", &n);


    c=facto(n);
printf("%f", c);

}

float facto(m)
int m;
{
    float sum;
    float fact;
    int j, i;
    sum=0.00;
    for(j=1; j<=m; ++j)
    {
        fact=1.00;
        for(i=1; i<=j; ++i)
        {
            fact=fact*i;
        }

        sum=sum+(fact/((float)(j)));
    }


    return(sum);
}
