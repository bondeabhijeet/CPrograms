#include<stdio.h>
#include<math.h>
int main()
{
    int n, p, z, count;
    double sum;

    printf("Enter the number:");
    scanf("%d", &n);
    z=n;  // STORING THE INPUT NUMBER IN A VARIABLE (z)
    count=0;
    while(n!=0)  // COUNTING THE NUMBER OF DIGITS
    {
        n=n/10;
        ++count;
    }

    n=z;  // AGAIN ASSIGNING THE NUMBER TO VARIABLE (n)
    sum=0.00;  // INITIALIZING THE SUM TO 0

    while(n!=0)
    {
        p=n%10;  // SEPERATING THE DIGIT AND STORING IT IN VARIABLE (p)
        n=n/10;
        sum = sum + pow((double)(p), (double)(count));  // CALCULATING SUM (ie. THE SEPERATED DIGIT TO THE POWER NUMBER OF DIGITS
    }

    n=z;  // AGAIN ASSIGNING THE VALUE TO THE VARIABLE (n)
    printf("%lf", sum);  // PRINTING THE CALCULATED SUM

    if(sum==(double)n)  // CHECKING THE ARMSTRONG CONDITION FOR PRINTING
    {
        printf("\nARMSTRONG NUMBER\n");
    }
    else
    {
        printf("\nNOT A ARMSTRONG NUMBER\n");
    }

}
