#include<stdio.h>
struct addr {
int zip;
int a;
char z;
}em;

int main()
{
    scanf("%d", &em.zip);
    scanf("%d", &em.a);
    scanf("%c", &em.z);

    printf("%d %d %c", em.zip, em.a, em.z);
}
