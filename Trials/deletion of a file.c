#include<stdio.h>

int main( void )
{
    int del;

    del = remove("ToBDeleted.txt");
    if( !del )
    {
        printf("\n\nSuccessfully deleted\n\n\a");
    }
    else
    {
        printf("\n\nERROR DELETING THE FILE ::\n\n\a");
    }
}
