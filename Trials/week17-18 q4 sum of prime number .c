#include<stdio.h>
void main()
{
    int n, i, j, count, a;
    int b[1000];
    printf("Enter a number");
    scanf("%d", &n);

    a=0;
    for(i=1; i<n; ++i)
    {
        count=0;
        for(j=1; j<=i; ++j)
        {
            if(i%j==0)
            {
                ++count;
            }
        }

        if(count==2)
        {
            b[a]=i;
            ++a;
        }
    }


    for(i=0; i<a; ++i)
    {
        for(j=i+1; j<a; ++j)
        {
            if(b[i]+b[j]==n)
            {
                printf("PAIRS ARE AS FOLLOWS");
                printf("%d %d\n", b[i], b[j]);
            }
        }
    }
}
