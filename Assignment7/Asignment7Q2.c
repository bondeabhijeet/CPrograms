#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct list
{
    int data;
    struct list *next;
};

int create_node(int element);
int menu(void);
int display(void);
int high_and_low(void);


struct list *start;

void main()  // MAIN
{
    int choice, find, element, freq;

    start = NULL;

    do
    {
        choice = menu();
        if(choice == 1)
        {
            printf("\n ENTER THE ELEMENT TO ADD IN THE LINKED LIST: ");
            scanf("%d", &element);  // ELEMENT TO BE ADDED
            printf("\n ENTERING THE CREATELIST FN \n");
            create_node(element);  // FUNCTION
        }
        if(choice == 2)
        {
            display();  // FUNCTION
        }
        if(choice == 3)
        {
            high_and_low();
        }
    }while(choice != 4);
}

int create_node(int element)
{
    struct list *record, *p_record;
    record = start;

    if(start == NULL)  // FOR FIRST ELEMENT ONLY
    {
        start = (struct list *)malloc(sizeof(struct list));
        start->next = NULL;  // PLACING NULL AT THE LINK SECTION OF THE FIRST ELEMENT
        start->data = element;  // PLACING THE DATA IN THE DATA PART OF THE FIRST ELEMENT
        printf("\n FIRST NODE CREATED SUCCESSFULLY AND ELEMENT PLACED %d \n", element);
        return(1);
    }
    else   // WHEN THERE ARE ELEMENTS IN THE LIST
    {
        while(record->next != NULL)  // TRAVERSIG TO LAST ELEMENT
        {
            record = record->next;
        }

        record->next = (struct list *)malloc(sizeof(struct list)); // ALLOCATING THE SPACE FOR THE NEW NODE
        record = record->next;  // MOVING TO THE NEWLY CREATED NODE
        record->next = NULL;  // PLACING NULL AT THE NEWLY CREATED NODE
        record->data = element;  // PLACING THE DATA IN THE NEWLY CREATED NODE
        printf("\n ELEMENT %d ADDED SUCCESSFULLY \n", element);
        return(1);
    }

}


int menu(void)  // MENU
{
    int choice;
    do
    {
        printf("\n 1 TO ADD ELEMENT \n");
        printf("\n 2 TO DISPLAY THE LIST \n");
        printf("\n 3 TO FIND LOWEST AND HIGHEST ELEMENT AND NUMBER OF ELEMENTS \n");
        printf("\n ENTER YOUR CHOICE>>>>> ");
        scanf("%d", &choice);
        if(choice<1 || choice>4)
        {
            printf("\n ENTER A VALID CHOICE \n");
        }
    }while(choice<1 || choice>4);

return(choice);
}


int high_and_low(void)
{
    int counter, highest, lowest;
    struct list *record;

    record = start;
    counter = 0;
    if(record == NULL)
    {
        printf("\n LIST HAS NO ELEMENTS \n");
        printf("\n THERE ARE 0 EEMENTS IN THE LIST \n");
        return(0);
    }
    while(record != NULL)
    {
        ++counter;
        record = record->next;

    }
    printf("\n NUMBER OF ELEMENTS ARE %d", counter);

    record = start;

    highest = record->data;
    lowest = record->data;

    while(record != NULL)
    {
        if(record->data > highest)
        {
            highest = record->data;
        }
        if(record->data < lowest)
        {
            lowest = record->data;
        }

        record = record->next;  // TRAVERING ONE POSITION FORWARD
    }

    printf("\n HIGHEST ELEMENT IN THE LIST IS %d \n", highest);
    printf("\n LOWEST ELEMENT IN THE LIST IS %d \n", lowest);


    return(counter);
}


int display(void)  // DISPLAY
{
    struct list *record;

    record = start;

    if(start == NULL)  // IF THE LIST HAS NO ELEMENTS
    {
        printf("\n LIST IS EMPTY \n");
    }

    do  // IF THE LIST HAS ELEMENTS
    {
        printf("%d   ", record->data);
        record = record->next;
    }while(record != NULL);
}

