#include<stdio.h>
void main()
{
    int r1, c1, i, j;
    scanf("%d %d", &r1, &c1);
    int a[r1][c1], b[c1][r1];

    for(i=0; i<r1; ++i)
    {
        for(j=0; j<c1; ++j)
        {
            scanf("%d", &a[i][j]);

        }
    }

    for(i=0; i<c1; ++i)
    {
        for(j=0; j<r1; ++j)
        {
            b[i][j]=a[j][i];
        }
    }
    printf("\n");
    for(i=0; i<c1; ++i)
    {
        for(j=0; j<r1; ++j)
        {
            printf("%d \t", b[i][j]);
        }
        printf("\n");
    }

}
