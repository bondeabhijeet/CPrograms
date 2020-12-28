#include<stdio.h>

struct info
{
    int enroll_no;
    float average_marks;
    char name[20];
    int age
};
void main()
{
    struct info entry;
    scanf("%d", &entry.enroll_no);
    scanf("%f", &entry.average_marks);
    scanf("%s", entry.name);
    scanf("%d", &entry.age);

    printf("  %d\n  %f\n  %s\n  %d\n", entry.enroll_no, entry.average_marks, entry.name, entry.age);
}
