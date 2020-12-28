#include<stdio.h>
int main()
{
    char time[10];
    int i;

    for(i=0; i<10; ++i)
    {
        scanf("%c",&time[i]);
    }
    if(time[8]=='P')
    {
        time[0] = time[0] + 1;
        time[1] = time[1] + 2;
    }

    for(i=0; i<8; ++i)
    {
        printf("%c", time[i]);
    }

}
