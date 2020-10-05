#include<stdio.h>
#include<stdlib.h>

int main()
{
    char ch;
    int count, count1;
    FILE *fp;
    if((fp=fopen("database.txt", "r"))==NULL)
    {
        printf("ERROR OPENING THE FILE.....");
        exit(0);
    }
    ch = fgetc(fp);
    count=0;
    count1=0;

    while(ch!=EOF)
    {
        if(ch == '\t')
        {
            count++;
        }
        if(ch == '\n')
        {
            count1++;
        }
        ch = fgetc(fp);
    }
    printf("total number of \\t=%d \n", count);
    printf("Total number of \\n=%d \n", count1);
}
