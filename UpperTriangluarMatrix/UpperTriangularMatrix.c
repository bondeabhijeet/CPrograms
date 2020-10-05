#include<stdio.h>
#include<stdlib.h>
void main()
{
    int m, n, i, j, FLAG;

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
        printf("GIVE ROW NO:%d \n", i);
        for(j=0; j<n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
        printf("\n");
    }

    FLAG =1;
    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if(j<i)
            {
               if(a[i][j]!=0)
               {
                   FLAG = 0;
               }
            }
        }
    }


    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }


    if(FLAG == 0)
    {
        printf("NOT A UPPER TRIANGULAR MATRIX");
    }
    else
    {
        printf("UPPER TRIANGULAR MATRIX");
    }
}
