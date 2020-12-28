#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m, n, i, j;

    printf("enter the number of rows:");
    scanf("%d", &m);
    printf("Enter the number of columns:");
    scanf("%d", &n);
    if(m!=n)
    {
        printf("ERROR!!!(m is not equal to n)\n");
        exit(0);
    }
    int a[m][n];
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(j<i)
            {
               if(a[i][j]==0)
               {
                   continue;
               }
               if(a[i][j]!=0)
               {
                   printf("ERROR!!!");
                   exit(0);
               }
            }
        }
    }
}
