#include<stdio.h>
#include<stdlib.h>

void main()
{
    int count, i, print;
    char str[1000];            /* Why 10000 ??, use 1000 */
    scanf("%s", str);          /* Why &str ??, use only str  */
    count=0;
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
    print=0;
    if(count%2==0)
    {
        for(i=0; i<(count/2); ++i)
        {
            if(str[i]==str[count-i-1])
            {

                continue;
            }
            else
            {
                printf("ERROR!!! NOT A PALINDROME");
                print=1;
                break;
            }
        }

    }
    if((count)%2!=0)
    {
        for(i=0; i<((count+1)/2)-1; ++i)
        {
            if(str[i]==str[count-i-1])
            {
                continue;

            }
            else   /* Why if again ??, you can use else here */
            {
                printf("ERROR!!!NOT A PALINDROME");
                print=1;
                break;
            }
        }

    }
    if(print==0)
    {
        printf("PALINDROME");
    }

}
