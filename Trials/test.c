#include<stdio.h>
void main()
{
    int i;
    char str[10];
    for(i=0; i<10; ++i)
    {
        scanf("%c", str[i]);
    }


    if(str[8]=='P')
    {
        printf("s");
        str[0]=str[0]+1;
        str[1]=str[1]+2;
    }
    for(i=0; i<10; ++i)
    {
        printf("%c", str[i]);
    }
}
