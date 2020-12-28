#include<stdio.h>
void main()
{
    int n, i, j;
    printf("ENTER STRING LENGHT:");
    scanf("%d", &n);
    char str[n];
    char str1[10]={'a','e','i','o','u','A','E','I','O','U'};
    scanf("%s", &str);
    for(i=0; i<n; ++i)
    {
        for(j=0; j<10; ++j)
        {
            if(str[i]==str1[j])
            {
                printf("%c is a vowel\n", str[i]);
            }
        }
    }

}
