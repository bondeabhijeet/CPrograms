#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int menu(void);
struct list *create (void);
int display(struct list *record);
int append(struct list *record);
struct list *prepend(struct list *record);
int insert(struct list *record);
struct list *delete (struct list *record);
struct list *reverselist(struct list *record);
struct list *free_memory(struct list *record);

struct list
{
    char name[80];
    struct list *next;
};

void main(void)
{
    int c;
    int choice;
    struct list *start;
    start = NULL;

    do
    {
        c=menu();
        if(c==1)
        {
            start = create();
            continue;
        }
        if(c==2)
        {
            append(start);
            continue;
        }
        if(c==3)
        {
            start = prepend(start);
            continue;
        }
        if(c==4)
        {
            insert(start);
            continue;
        }
        if(c==5)
        {
            start = delete(start);
            continue;
        }
        if(c==6)
        {
            start = reverselist(start);
            continue;
        }
        if(c==7)
        {
            display(start);
            continue;
        }
        if(c==8)
        {
            printf("EXITING PROGRAM.....\n");
            start = free_memory(start);
            exit(0);
        }
        if(c==9)
        {
            start = free_memory(start);
            continue;
        }

    }while(choice!=9);
}


int menu(void)
{
    int choice;
    do
    {
        system("cls");
        printf("        MENU \n");
        printf("ENTER 1 TO CREATE LIST \n");
        printf("ENTER 2 TO APPEND ELEMENT TO THE LIST \n");
        printf("ENTER 3 TO PREPEND ELEMENT TO THE LIST \n");
        printf("ENTER 4 TO INSERT ELEMENT INBETWEEN THE LIST \n");
        printf("ENTER 5 TO DELETE SPECIFIC ELEMENT IN A LIST \n");
        printf("ENTER 6 TO REVERSE THE LIST \n");
        printf("ENTER 7 TO DISPLAY THE LIST \n");
        printf("ENTER 8 TO EXIT THE PROGRAM \n");
        printf("ENTER 9 TO FREE UP THE MEMORY \n\n");
        printf("ENTER YOUR CHOICE-----> ");
        scanf("%d", &choice);
        if(choice<1 || choice>9)
        {
            printf("\n ENTER A VALID INPUT!!!!! \n");
        }
    }while(choice<1 || choice>9);


    return(choice);
}

struct list *create (void)  // CREATING A LINKED LIST
{
    struct list *start, *record;
    char name[80];
    printf("ENTER THE ELEMENT TO BE ADDED TO THE LIST......TYPE (END) TO TERMINATE THE LIST \n");
    scanf(" %[^\n]", name);
    if(!strcmp(name,"END")) // WHEN THE LIST HAS NO ELEMENT
    {
        return(NULL);
    }

    start =(struct list *)malloc(sizeof(struct list));
    record =start;

    while(strcmp(name,"END"))   // WHEN LIST HAS TO BE CREATED
    {
        strcpy(record->name,name);
        printf("%s COPIED TO LIST\n\n", record->name);
        record->next=NULL;
        printf("ENTER THE ELEMENT......\n");
        scanf(" %[^\n]", name);
        if(strcmp(name,"END"))
        {
            record->next = (struct list *)malloc(sizeof(struct list));
            record = record->next;
        }
    }
    return(start);
}


int append(struct list *record)  // FUNCTION TO ADD ELEMENT AT THE END
{
    struct list *N_node;
    char name[80];
    if(record == NULL)   // WHEN THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY \n");
        return(0);
    }
    printf("\n ENTER THE NAME TO BE APPENDED: \n");  // THE NAME TO BE APPENDED IS TAKEN
    scanf(" %[^\n]", name);
    if(!strcmp(name, "END"))  // THE INPUT NAME IS COMPARED TO END, IN CASE THE USER DOES NOT WANT TO ADD ANYTHING
    {
        printf("\n NOTHING APPENDED \n");  // NOTHING ADDED AS NAME IS EQUAL TO END
        return(0);
    }
    while(record->next)  // FINDING THE LAST RECORD (WHERE RECORS->NEXT IS NULL) OR FINDING THE END OF THE LIST
    {
        record = record->next;
    }
    N_node = (struct list *)malloc(sizeof(struct list)); // LOCATING SPACE FOR THE NEW ELEMENT WHICH HAS TO BE ADDED AT THE END
    N_node->next = NULL;     // KEEPING NULL AT THE ADDRESS BAR OF THE NEWLY CREATED NODE, AS IT WILL BE OUR NEW END OF THE LIST
    record->next = N_node;   // LINKING THE NEWLY CREATED NODE WITH THE LINKED LIST
    strcpy(N_node->name, name); // COPYING THE DATA TO THE LAST ELEMENT
    return(0);
}


struct list *prepend(struct list *record)  // FUNCTION TO ADD ELEMENT AT THE START
{
    struct list *N_node, *start;
    char name[80];
    start = record;
    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        return(start);
    }
    printf("\n ENTER THE NAME TO BE PREPENDED: \n"); // IF THE LIST ELEMENTS THEN, TAKING INPUT FOT THE NAME TO BE ADDED A THE BEGINING OF THE LIST
    scanf(" %[^\n]", name);
    if(!strcmp(name, "END"))  // CHECKING IF THE USER DOES NOT WANTS TO ADD ANYTHING
    {
        printf("\n NOTHING PREPENDED \n");
        return(start);
    }
    N_node = (struct list *)malloc(sizeof(struct list));
    N_node->next = start;  // LINKING THE NEW STARTING ADDRESS TO THE LIST(ie. THE OLD START)
    start = N_node;  // UPDATING THE STARTING ADDRESS (AS NOW STARTING ADDRESS WOULD BE THE ADDRESS OF THE NEWLY ADDED ELEMENT)
    strcpy(N_node->name, name);  // COPYING THE DATA TO THE NEWLY CREATED STARTING ELEMENT
    return(start);  // RETURNING START AS THE START HAS BEEN UPDATED DUE TO ADDITION OF NEW ELEMENT ELEMENT AT THE BEGINING
}



int insert(struct list *record)  // FUNCTION TO ADD ELEMENT INBETWEEN THE LIST
{
    struct list *N_node, *F_node;
    char N_name[80];
    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY \n");
        return(0);
    }
    printf("\n INSERT AFTER (NAME) ??: \n");  // TAKING THE INPUT FOR THE LIST ELEMENT AFTER WHICH THE NEW ELEMENT HAS TO BE PLACED
    scanf(" %[^\n]", N_name);
    while(strcmp(record->name,N_name))  // GETTING THE NODE AFTER WHICH THE EEMENT HAS TO BE ADDED IN THE LIST BY TRAVERSING THROUGH THE LIST
    {
        if(record->next==NULL)   // IF THE ENTERED ELEMENT IS NOT FOUND IN THE LIST
        {
            printf("\n NO SUCH ENTRY FOUND.....\n");
            return(0);
        }
        record= record->next; // SHIFTING THE RECORD POINTER FORWARD
    }
    N_node=(struct list *)malloc(sizeof(struct list));
    printf("ENTER THE NAME TO BE ADDED: \n");  // TAKING THE INPUT FOR THE DATA, WHICH HAS TO BE ADDED INBETWEEN
    scanf(" %[^\n]", N_node->name);
    F_node = record->next;  // COPYING THE ADDRESS OF THE NEXT FIELD OF THE NODE BEFORE THE NEW NODE IN A TEMPORARY VARIABLE
    record->next=N_node;    // LINKING THE NEWLY CREATED NODE TO ITS PREVIOUS
    N_node->next=F_node;    // COPYING THE ADDRESS FROM THE REMPORARY VARIABLE TO THE NEXT FIELD OF NEWLY CREATED NODE FOR LINKING OF NEXT EEMENT
    return(0);
}


struct list *delete (struct list *record)
{
    struct list *start, *N_node, *P_node;
    char N_delete[80];
    start = record;
    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY \n");
        return(0);
    }
    printf("\n ENTER THE ELEMENT TO BE DELETED: \n");
    scanf(" %[^\n]", N_delete);
    if(!strcmp(start->name, N_delete)) //FIRST NODE IS BEING DELETED
    {
        printf("FIRST ELEMENT IS BEING DELETED \n");
        free(start);
        start= record->next;
        return(start);
    }
    while(strcmp(record->name, N_delete))//MATCH NOT FOUND SO NO NODE IS DELETED
    {
        P_node = record;
        if(record->next == NULL)
        {
            printf("ELEMENT NOT FOUND \n");
            return(start);
        }
        record = record->next;
    }
    if(record->next==NULL)//LAST NODE IS BEING DELETED
    {
        printf("LAST ELEMENT IS BEING DELETED \n");
        P_node->next=NULL;
        free(record);
        return(start);
    }
    else                      //INBETWEEN NODE IS BEING DELETED
    {
        printf("INBETWEEN ELEMENT IS BEING DELETED \n");
        P_node->next = record->next;
        free(record);
        return(start);
    }
}

struct list *reverselist(struct list *record)
{
    struct list *previous, *current, *next, *start;
    previous = NULL;  // INITIALIZING THREE POINTERS
    current = record;
    next = NULL;

    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        return(record);
    }

    while (current!= NULL)
    {
        next = current->next;  // POINTING THE NEXT NODE
        current->next = previous;  // LINKING BACK ELEMENT WITH THE FORWARD ELEMENT FOR REVERSING
        previous = current;  // CURRENT NODE IN THE LAST (ie. PREVIOUS) ITTRATION BECOMES PREVIOUS NODE IN THIS ITTRTAION
        current = next;  // NEXT NODE IN THE PREVIOUS ITTRATION WILL BECOME CURRENT NODE IN THIS ITTRATION
    }
    start = previous;  // THE LAST ELEMENT IN THE LIST WILL NOW BECOME THE STRATING ELEMENT IN THE NEW LIST
    return(start);  // RETURNING THE NEW START
}

struct list *free_memory(struct list *record)
{
    struct list *P_record;
    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        return(record);
    }

    do
    {
        P_record = record;
        record = record->next;
        printf("%s FREED \n", P_record->name);
        free(P_record);
    }while(record!= NULL);
    printf("PRESS ANY KEY TO CONTINUE \n");
    getch();
    return(NULL);
}



int display(struct list *record)
{
    if(record == NULL)  // CHECKING IF THE LIST IS EMPTY
    {
        printf("\n LIST IS EMPTY.... \n"); // IF THE LIST IS EMPTY THEN PRINT AND RETURN
        printf("\nPRESS ANY KEY TO CONTINUE \n");
        getch();
        return(0);
    }

    do
    {
        printf("%s \n", record->name);
        record = record->next;
    }while(record!= NULL);
    printf("\nPRESS ANY KEY TO CONTINUE \n");
    getch();
    return(0);
}


