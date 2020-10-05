#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main (void)
{
    FILE *fp, *fp1;
    char filename[80], c, str[200], str1[200];
    int i;

    if((fp=fopen("new.txt", "rt"))==NULL)
    {
        printf("\n ERROR OPENING FILE 1 \n");
    }

    if((fp1=fopen("new1.txt", "wt"))==NULL)
    {
        printf("\n ERROR OPENING FILE 2 \n");
    }
    int count = 0;
    do
    {
        fscanf(fp, " %[^\n]", str);
        printf("%s \n", str);

        i=0;
        while(str[i] != ' ')
        {
            str1[i]=str[i];
            ++i;
        }
        str1[i]='\n';

        fprintf(fp1, "%s \n", str1);
        count++;


    }while(count < 10);

    fclose(fp);
    fclose(fp1);
}
