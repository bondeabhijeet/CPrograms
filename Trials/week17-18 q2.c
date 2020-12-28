#include<stdio.h>
int prime_no(int, int);
void main()
{
    int n, m;
    printf("Enter the lower interval(>1):");
    scanf("%d", &n);
    printf("Enter the upper interval:");
    scanf("%d", &m);

    prime_no(n,m);
}

int prime_no(int t, int s)
{
    int i, j, c;
    for(i=t; i<s; ++i)
    {
        c=0;
        for(j=1; j<=i; ++j)
        {
            if(i%j==0)
            {
                ++c;
            }
        }
        if(c==2)
        {
            printf("%d\n", i);
        }
    }
}
