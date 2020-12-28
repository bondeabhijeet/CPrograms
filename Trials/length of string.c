#include<stdio.h>
#include<stdlib.h>

void main()
{
    int  i, count;
    char str[10000];
    scanf("%s", &str);
    count=0;
    for(i=0;i<1000; ++i)
    {

        if(str[i]!='\0')
        {
            ++count;
        }
        if(str[i]=='\0')
        {
            break;
        }
    }
    printf("%d", count);
}
