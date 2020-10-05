#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int push(int item);
int pop(int *item);
int display(void);
int menu(void);

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top;

void main()
{
    int item, choice, popped_element;
    top =  NULL;
    do
    {
        choice = menu();
        if(choice==1)
        {
            printf("\n ENTER THE ELEMENT TO BE PUSHED: ");
            scanf("%d", &item);
            if(push(item))
            {
                printf("\n ITEM PUSHED ONTO THE STACK IS %d \n", item);
            }
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();

        }
        if(choice == 2)
        {
            printf("\n ELEMENT IS BEING POPPED \n");
            if(pop(&popped_element))
            {
                printf("ELEMENT POPPED IS %d", popped_element);
            }
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
        if(choice == 3)
        {
            display();
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
    }while(choice!=4);
}
int menu(void)
{
    int choice;
    do
    {
        system("cls");
        printf("\n 1 TO PUSH ONTO THE STACK \n");
        printf("\n 2 TO POP ELEMENT FROM STACK \n");
        printf("\n 3 TO DISPLAY STACK CONTENT \n");
        printf("\n ENTER YOUR CHOICE >>>>>> ");

        scanf("%d", &choice);
        if(choice<1 || choice>4)
        {
            printf("\n ENTER A VALID OPTION \n");
        }
    }while(choice<1 || choice>4);

    return(choice);
}

int push(int item)
{
    struct stack *n_node;
    n_node=(struct stack *)malloc(sizeof(struct stack));
    if(n_node != NULL)
    {
        n_node->data = item;
        if(top == NULL)
        {
            n_node->next =NULL;
        }
        else
        {
            n_node->next = top;
        }
        top = n_node;
        return(1);
    }
    else
    {
        printf("\n OUT OF MEMORY \n");
        return(0);
    }
}

int pop(int *item)
{
    struct stack *previous;
    if(top == NULL)
    {
        printf("\n STACK IS EMPTY \n");
        return(0);
    }
    else
    {
        *item = top->data;
        previous = top;
        top= top->next;
        free(previous);
        return(1);
    }
}

int display(void)
{
    struct stack *temp_top;

    temp_top = top;

    if(top == NULL)
    {
        printf("\n STACK IS EMPTY \n");
        return(0);
    }
    else
    {
        printf("\n CONTENT OF STACK IS: ");

        do
        {
            printf("%d  ", temp_top->data);
            temp_top= temp_top->next;
        }while(temp_top!=NULL);

        printf("\n");

        return(1);
    }
}

