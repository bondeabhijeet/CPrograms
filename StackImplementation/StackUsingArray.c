#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int pop(int *poped_element);
int push(int topush);
int menu(void);
void display(void);
int stack[100], top, n, choice;

void main(void)
{
    int topush, d, poped_element;
    printf("ENER THE MAXIMUM SIZE OF STACK: ");      // TO ASSIGN THE SIZE OF THE STACK
    scanf("%d", &n);
    top=-1;  // INITIALIZING TOP OF THE STACK
    do
    {
        choice = menu();
        if(choice==1)  // TO PUSH A ELEMENT ONTO THE STACK
        {
            printf("\n ENTER THE ELEMENT TO BE PUSHED: ");
            scanf("%d", &topush);
            if(push(topush))        // THE IF STATEMENT IS FOR CHECKING IF THE VALUE RETURNED BY THE PUSH FUNTION IS TRUE OR FALSE
            {
                printf("\n ELEMENT(%d )PUSHED ON STACK\n\n", topush);
            }
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
        if(choice == 2)  // TO POP AN ELEMENT FROM THE STACK
        {
            d = pop(&poped_element);

            if(d)  // TO CHECK IF THE RETURNED VALUE IS TRUE OR FALSE
            {
                printf("ELEMENT POPPED IS %d \n", poped_element);  // PRINT ONLY IF THE ELEMENT IS ACTUALLY POPPED
            }

            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
        if(choice == 3)  // TO DISPLAY THE STACK CONTENT AT A  PARTICULAR MOMENT
        {
            display();
            printf("PRESS ANY KEY TO CONTINUE");
            getch();
        }

    }while(choice!=4);
}

void display(void)
{
    int i;
    if(top>=0)  // CHECKING IF THE STACK HAS ANY ELEMENTS
    {
        printf("CURRENT STACK CONTENT: ");
        for(i=top; i>=0; --i)
        {
            printf("%d  ", stack[i]);

        }
        printf("\n\n");
    }
    else
    {
        printf("\n >>>>>  STACK IS EMPTY  <<<<< \n\n");
    }

}

int push(int topush)
{
    if(top>= n-1)  // CHECKING IF THE STACK IS FULL
    {
        printf("\n STACK OVERFLOW, CANT BE PUSHED \n\n");
        return(0);
    }
    else  // IF THE STACK IS FULL
    {
        top++;
        stack[top]=topush;
        return(1);
    }
}

int menu(void)
{
    int choice;
    do
    {
        system("cls");
        printf(" 1 TO PUSH ELEMENT \n");
        printf(" 2 TO POP THE ELEMENT \n");
        printf(" 3 TO DISPLAY THE ELEMENTS \n");
        printf(" 4 TO EXIT THE PROGRAM \n");
        printf("\n ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        if(choice<1 || choice>4)
        {
            printf("\n ENTER A VALID OPTION \n");
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
    }while(choice<1 || choice>4);

    return(choice);
}

int pop(int *poped_element)
{

    if(top < 0)  // CHECKING IF THE STACK IS EMPTY
    {
        printf("STACK UNDERFLOW \n");
        return(0);
    }
    else
    {
        *poped_element = stack[top];
        top--;
        return(1);
    }
}

