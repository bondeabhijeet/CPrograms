#include<stdio.h>
void main()
{
    char str[1000];
    char str1[1000];
    int i, j;
    scanf("%s", &str);

    i=0;
    while(str[i]!='\0')
    {
        str1[i]=str[i];
        ++i;
    }

    for(j=0; j<i; ++j)
    {
        printf("%c", str1[j]);
    }
}
