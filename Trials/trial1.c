#include<stdio.h>
int hello(int,char,char[],int[]);
void main()
{
    int x,i;
    char str[50];
    int xx[20];
    char q;

    scanf("%c",&q);
    scanf("%d",&x);
    scanf("%s",str);
    for(i=0; i<5; ++i)
    {
        scanf("%d", &xx[i]);
    }

    hello(x,q,str,xx);
}

int hello(int x,char q,char str[],int xx[])
{
    int i;
    printf("%d %s", x, str);
    for(i=0; i<5; ++i)
    {
        printf("%d", xx[i]);
    }
    printf("%c", q);
    return 0;
}
