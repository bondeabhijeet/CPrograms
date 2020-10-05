#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct list
{
    char data;
    struct list *next;
};

int create_node(char name[]);
int menu(void);
int display(void);
int remove_vowel();


struct list *start;

void main()  // MAIN
{
    int choice;
    char name[80];

    start = NULL;

    do
    {
        choice = menu();
        if(choice == 1)
        {
            printf("\n ENTER THE NAME \n");
            scanf("%s", name);
            printf("\n ENTERING THE CREATELIST FN \n");
            create_node(name);  // FUNCTION
        }
        if(choice == 2)
        {
            display();  // FUNCTION
        }
        if(choice == 3)
        {

            remove_vowel();
        }
    }while(choice != 4);
}

int create_node(char name[])
{
    struct list *record, *p_record;
    int i;
    i=0;
    record = start;


    if(name == '\0')
    {
        printf("\n NO INPUT GIVEN \n");
        return(0);
    }
    if(start == NULL)  // FOR FIRST ELEMENT ONLY
    {
        start = (struct list *)malloc(sizeof(struct list));
        start->next = NULL;  // PLACING NULL AT THE LINK SECTION OF THE FIRST ELEMENT
        start->data = name[i];  // PLACING THE DATA IN THE DATA PART OF THE FIRST ELEMENT
        record = start;
        ++i;
        printf("\n FIRST NODE CREATED SUCCESSFULLY AND ELEMENT PLACED %c", record->data);
        while(name[i] != '\0')
        {
            record->next = (struct list *)malloc(sizeof(struct list));
            record = record->next;
            record->next = NULL;
            record->data = name[i];
            printf("%c", record->data);
            ++i;
        }
    }
    printf("\n %c done \n", record->data);
}


int menu(void)  // MENU
{
    int choice;
    do
    {
        printf("\n 1 TO CREATE A LINKED LIST FROM A NAME \n");
        printf("\n 2 TO DISPLAY THE LIST \n");
        printf("\n 3 TO REMOVE THE VOWEL FROM THE CREATED LIST \n");
        printf("\n ENTER YOUR CHOICE>>>>> ");
        scanf("%d", &choice);
        if(choice<1 || choice>4)
        {
            printf("\n ENTER A VALID CHOICE \n");
        }
    }while(choice<1 || choice>4);

return(choice);
}


int remove_vowel()
{
    int i;
    struct list *record, *p_record, *c_record;

    record = start;

    if(start == NULL)
    {
        printf("\n hello!!  LIST HAS NO ELEMENTS \n");
        return(0);
    }

    while(record != NULL)
    {
        if(record->data == 'a' || record->data == 'e' || record->data == 'i'|| record->data == 'o'|| record->data == 'u')
        {
            /*if(record == start)
            {
                start = record->next;
                printf("\n FIRST FREED %c\n", record->data);
                //free(record);
                //record = start;

            }
            else  if(record->next == NULL)
            {
                p_record->next = NULL;
                printf("\n LAST FREED %c\n", record->data);
                free(record);

            }
            else
            {
                n_record = record;
                record = record->next;
                p_record->next = n_record->next;
                printf("\n MIDDLE FREED %c\n", n_record->data);
                free(n_record);
                record = record->next;

            }*/


            if(record == start)
            {
                start = start->next;
                printf("\n START RECORD FREED: %c \n", record->data);
                free(record);
                record = start;
                continue;
            }
            else if( record->next == NULL)
            {
                p_record->next = NULL;
                printf("\n END RECORD FREED: %c \n", record->data);
                free(record);
                record = NULL;
            }
            else
            {
                p_record->next = record->next;
                c_record = record;
                record = record->next;
                printf("\n MIDDLE RECORD FREED: %c \n", c_record->data);
                free(c_record);
                continue;
            }
        }
        else
        {
            p_record = record;
            record = record->next;
        }

       // p_record = record;
        //printf("%c done", record->data);

       //record = record->next;  // TRAVERING ONE POSITION FORWARD
    }

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


