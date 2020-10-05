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
int remove_duplicate(void);

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
            printf("\n REMOVING DUPLICATES \n");
            remove_duplicate();
            printf("HELLO");
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
        printf("\n 3 TO REMOVE THE DUPLICATES \n");
        printf("\n ENTER YOUR CHOICE>>>>> ");
        scanf("%d", &choice);
        if(choice<1 || choice>4)
        {
            printf("\n ENTER A VALID CHOICE \n");
        }
    }while(choice<1 || choice>4);

return(choice);
}


int remove_duplicate(void)
{
    struct list *f_record, *s_record, *p_record;
    f_record = start;
    if(start == NULL)
    {
        printf("\n LIST IS EMPTY \n");
        return(0);
    }

    while(f_record != NULL)
    {
        p_record = f_record;
        s_record = f_record->next;
        while(s_record != NULL)
        {
            if(f_record->data == s_record->data)
            {
                if(s_record->next == NULL)
                {
                    p_record->next = NULL;
                    printf("\n ELEMENT REMOVE IS %d\n", s_record->data);
                    free(s_record);
                    s_record = NULL;
                }
                else
                {
                    p_record->next = s_record->next;
                    printf("\n ELEMENT REMOVE IS %d\n", s_record->data);
                    free(s_record);
                    s_record = p_record->next;
                }
            }
            else
            {
                printf("\n ELEMENT skipped is IS %d", s_record->data);
                p_record = p_record->next;
                s_record = s_record->next;
            }
        }
        f_record = f_record->next;
    }
    return(1);
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


