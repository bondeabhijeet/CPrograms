#include<stdio.h>
#include<stdlib.h>
void main()
{
    int r1, c1, r2, c2, i, j;
    printf(" input number of rows and columns for matrix 1\n");
    scanf("%d  %d", &r1, &c1);
    printf(" input number of rows and columns for matrix 2\n");
    scanf("%d  %d", &r2, &c2);

    if(c1!=c2 || r1!=r2)
    {
        printf("ERROR");
        exit(0);
    }
    int q[r1][c1], w[r2][c2], c[r1][c1];
    printf("Enter the elements row wise for 1st matrix\n");

    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c1; ++j)
        {
            scanf("%d", &q[i][j]);
        }

    }
    printf("Enter the elements row wise for 2nd matrix\n");
    for(i=0; i<r2; ++i)
    {
        for(j=0; j<c2; ++j)
        {
            scanf("%d", &w[i][j]);
        }

    }
    printf("Adding.....\n");
    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c1; ++j)
        {
            c[i][j] = q[i][j] + w[i][j];
        }

    }
    printf("\n");

    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c1; ++j)
        {
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }

}
