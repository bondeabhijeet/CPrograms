#include<stdio.h>
void main()
{
    char str[1000], str1[1000];
    int count, count1, i;
    scanf("%s", str);
    scanf("%s", str1);

    count=0;
    count1=0;
    for(i=0; i<1000; ++i)
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
    for(i=0; i<1000; ++i)
    {
        if(str1[i]!=0)
        {
            ++count1;
        }
        if(str1[i]=='\0')
        {
            break;
        }
    }

    for(i=0; i<count1; ++i)
    {
        str[count+i]=str1[i];
    }
    str[(count1+count)]='\0';
    printf("%s\n\n", str);
    printf("Length of first string is:%d \nand of second is:%d", count, count1);

}
