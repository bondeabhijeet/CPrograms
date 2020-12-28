#include<stdio.h>
struct hello
{
    int x;
    char y;
    int b[50];
    char f[20];
};
void main()
{
    struct hello a;
    int i;
 scanf("%s", a.f);
    scanf("%d", &a.x);
    scanf("%c", &a.y);
    for(i=0; i<5; ++i)
    {
        scanf("%d", &(a.b[i]));
    }

    printf("%d\n", a.x);
   printf("%c\n", a.y);
    printf("%s\n", a.f);
    for(i=0; i<5; ++i)
    {
        printf("%d\n", a.b[i]);
    }
}
