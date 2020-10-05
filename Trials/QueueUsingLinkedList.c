#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int menu(void);
int add(int item);
int delete(int *item);
int display(void);
int free_memory(void);

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front, *rear;

void main()
{
    int choice, item, returned_value;

    front = NULL;
    rear = NULL;
    do
    {
        choice = menu();
        if(choice == 1)
        {
            printf("\n ENTER THE ELEMENT TO BE ADDED: ");
            scanf("%d", &item);
            if(add(item))  // CHECKING IF THE PROCESS OF ADDING ELEMENT IN THE QUEUE WAS SUCCESSFUL OR NOT
            {
                printf("\n ELEMENT %d ADDED TO THE REAR END OF THE QUEUE \n", item);
            }
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
        if(choice == 2)
        {
            returned_value = delete(&item);
            if(returned_value)  // CHECKING IF THE PROCESS OF DELETEING THE ELEMENT WAS SUCCESSFUL IN A QUEUE
            {
                printf("\n ELEMENT %d SUCCESSFULLY DELETED :) \n", item);
            }
            else
            {
                printf("\n ERROR DELETING THE ELEMENT \n");
            }
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
        if(choice == 3)  // CHECKING IF THE PROCESS OF DISPLAYING THE CIONTENT IN A QUEUE WAS SUCCESSFUL OR NOT
        {
            if(display())
            {
                printf("\n ELEMETNTS PRINTED SUCCESSFULLY..... \n");
            }
            else
            {
                printf("\n ERROR IN PRINTING ALL THE ELEMENTS \n");
            }
            printf("\n PRESS ANY KEY TO CONTINUE \n");
            getch();
        }
        if(choice == 4) // CHECKING IF THE PROCESS OF FREEING UP THE MEMORY WAS SUCCESSFUL OR NOT
        {
            if(free_memory())
            {
                printf("\n MEMORY FREED SUCCESSFULLY \n");
            }
            else
            {
                printf("\n EITHER LIST IS EMPTY OR ERROR FREEING UP THE MEMORY \n");
            }
        }
    }while(choice!=4);
}

int menu(void)  // MENU
{
    int choice;
    do
    {
        system("cls");
        printf("\n 1 TO ADD THE ELEMENT TO THE QUEUE \n");
        printf("\n 2 TO DELETE A ELEMENT FROM THE QUEUE \n");
        printf("\n 3 TO DISPLAY THE CONTENT OF THE QUEUE \n");
        printf("\n 4 TO EXIT THE PROGRAM \n");
        printf("\n ENTER YOUUR CHOICE-> ");
        scanf("%d", &choice);
        if(choice<1 || choice>4)
        {
            printf("\n ENTER A VALID INPUT \n");
        }
    }while(choice<1 || choice>4);

    return(choice);
}


int add(int item)
{
    if(rear == NULL)  // IF CONDITION WILL ONLY WORK IF THE ELEMENT IS FIRST
    {
        rear =(struct queue *)malloc(sizeof(struct queue));
        if(rear ==  NULL)
        {
            printf("\n MEMORY ALLOCATION FAILED!!! \n");
            return(0);
        }
        rear->data = item;
        rear->next = NULL;
        front = rear;
        return(1);
    }
    else  // IF THERE IS ATLEAST ONE ELEMENT IN THE QUEUE
    {
        rear->next = (struct queue *)malloc(sizeof(struct queue));  // ALLOCATING MEMORY FOR THE NEXT ELEMENT
        if(rear->next == NULL)  // CHECKING IF TH MEMORY IS ALLOCATED SUCCESSFULLY IN THE PREVIOUS STEP
        {
            printf("\n MEMORY ALLOCATION FAILED!!! \n");
            return(0);
        }
        rear= rear->next;   // MOVING THE REAR POINTER TO THE NEWLY CREATED NODE
        rear->data = item;  // PLACING THE DATA IN THE LINKED LIST
        rear->next = NULL;  // PLACING NULL AT THE LINK PRTION OF TE NEWLY CREATED ELEMENT
        return(1);
    }
}

int delete(int *item)
{
    struct queue *previous;

    if(front == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY \n");
        return(0);
    }

    // IF THE LIST HAS ELEMENTS

    *item = front->data;  // PLACING THE DELETED ELEMENT IN ITEM FOR  FURTHER USE OF THE DELETED ELEMENT
    previous = front;
    front =  front->next;
    free(previous);
    if(front == NULL)  // IF (FRONT == NULL) IS TRUE THEN THE LIST IS EMPTY. THEREFORE, REAR SHOULD ALSO BE NULL
    {
        rear = NULL;  // SO ASSIGNING REAR = NULL
    }

    return(1);
}

int display(void)
{
    struct queue *temp_front;
    temp_front= front;  // NOT TO ALTER THE VARIABLE FRONT AS IT IS GLOBAL VARIABLE
    if(front == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY \n");
        return(0);
    }

     // IF THE LIST IS NOT EMPTY THEN DISPLAYING THE CONTENT

    printf("\n LIST CONTENT IS: ");
    do
    {
        printf("%d  ", temp_front->data);
        temp_front= temp_front->next;
    }while(temp_front != NULL);
    return(1);
}

int free_memory(void)  // FREEING UP THE MEMORY
{
    struct queue *p_record;
    if(front== NULL)  // CHECKING IF THE QUEUE IS ALREAD EMPTY
    {
        printf("\n LIST IS ALREADY EMPTY \n");
        return(0);
    }

    // IF THE QUEUE IS NOT EMPTY THEN FREEING UP THE MEMORY

    do
    {
        p_record = front;  // STORING THE FRONT IN A VARIABLE SO THAT IT CAN BE FREED AND MOVE TO THE NEXT ELEMENT SIMULTANEOUSLY
        front= front->next;
        printf("\n FREED ELEMENT: %d \n", p_record->data);
        free(p_record);  // FREEING UP THE MEMORY
    }while(front != NULL);

    return(1);
}
