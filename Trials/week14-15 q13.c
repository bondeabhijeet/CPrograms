#include<stdio.h>

struct marks
{
    int roll_no;
    char name[20];
    float chem_marks;
    float maths_marks;
    float phy_marks;
};
void main()
{
    struct marks entry[5];
    int i;

    for(i=0; i<5; ++i)
    {
        scanf("%d", &entry[i].roll_no);
        scanf("%s", entry[i].name);
        scanf("%f", &entry[i].chem_marks);
        scanf("%f", &entry[i].maths_marks);
        scanf("%f", &entry[i].phy_marks);
    }

    for(i=0; i<5; ++i)
    {
        printf("%d", entry[i].roll_no);
        printf("%s", entry[i].name);
        printf("%f", entry[i].chem_marks);
        printf("%f", entry[i].maths_marks);
        printf("%f", entry[i].phy_marks);
    }

}
