/* ********************************************************************************************
/* @name     : MAIN.C
/* @brief    : TEST PROGRAM OF THE SINGLE linked LIST
/* @author   : TAREK ALLAM
/***********************************************************************************************/
/*************************************** START INCLUDES ****************************************/
#include "errorState.h"
#include "single_list.h"
#include "stdTypes.h"

#include <stdio.h>

/*************************************** END INCLUDES ******************************************/
/*************************************** START MAIN ********************************************/
int main()
{
    node_t *head1 = NULL;

    list_insertNodeEnd(&head1, 11);
    list_insertNodeEnd(&head1, 21);
    list_insertNodeEnd(&head1, 11);
    list_insertNodeEnd(&head1, 23);

    list_showItems(head1);
    printf("\n--------------------------------------\n");
    list_reverse(&head1);
    list_showItems(head1);

    return 0;
}
/*************************************** END MAIN **********************************************/

/************************************************************************************************
 * AUTHOR              DATE                    BRIEF
 ************************************************************************************************
 * TAREK ALLAM         2 NOV 2022             TEST program
 * TAREK ALLAM         3 NOV 2022             TEST REVERSE FUNCTION
 */