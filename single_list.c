/* ********************************************************************************************
/* @name     : QUEUE.C
/* @brief    : PROGRAM OF THE single linked list
/* @author   : TAREK ALLAM
/***********************************************************************************************/

/*************************************** START INCLUDES ****************************************/
#include "single_list.h"
#include "errorState.h"
#include "stdTypes.h"

#include <stdio.h> // for display queue
#include <stdlib.h>

/*************************************** END INCLUDES ******************************************/

/*************************************** START PROGRAMS ************************************/
ES_t list_insertNodeEnd(struct node **headList, uint32 nodeData)
{
    ES_t ErrorState_local = ES_NOK;
    struct node *createdNode = NULL;
    struct node *tempNode = NULL;
    createdNode = (struct node *)malloc(sizeof(struct node));

    if (createdNode != NULL)
    {
        createdNode->nextNode = NULL;
        createdNode->dataNode = nodeData;
        if (*headList == NULL)
        {
            *headList = createdNode;
        }
        else
        {
            tempNode = *headList;
            while (tempNode->nextNode != NULL)
            {
                tempNode = tempNode->nextNode;
            }

            tempNode->nextNode = createdNode;
        }
    }
    else
    {

        ErrorState_local = ES_NOK;
    }
    return ErrorState_local;
}

ES_t list_insertNodeBegging(struct node **headList, uint32 nodeData)
{
    ES_t ErrorState_local = ES_NOK;
    struct node *createdNode = NULL;
    createdNode = (struct node *)malloc(sizeof(node_t));
    if (createdNode != NULL)
    {
        createdNode->dataNode = nodeData;
        createdNode->nextNode = *headList;
        *headList = createdNode;
    }
    else
    {
        ErrorState_local = ES_NOK;
    }

    return ErrorState_local;
}

ES_t list_insertNodeAfter(struct node *headList, uint32 nodeData, uint32 nodeNumber)
{
    ES_t ErrorState_local = ES_NOK;
    struct node *createdNode = NULL;
    struct node *tempNode = NULL;
    struct node *AftertempNode = NULL;
    tempNode = headList;
    createdNode = (struct node *)malloc(sizeof(node_t));
    uint32 counter;
    if ((headList != NULL) && (nodeNumber > 0) && (nodeNumber < list_GetLength(headList)))
    {
        createdNode->dataNode = nodeData;
        createdNode->nextNode = NULL;
        for (counter = 0; counter < nodeNumber - 1; counter++)
        {
            tempNode = tempNode->nextNode;
        }
        AftertempNode = tempNode->nextNode;
        tempNode->nextNode = createdNode;
        createdNode->nextNode = AftertempNode;
        ErrorState_local = ES_OK;
    }

    return ErrorState_local;
}

ES_t list_showItems(struct node *node)
{
    ES_t ErrorState_local = ES_NOK;
    uint32 counter = 1;
    while (node != NULL)
    {
        printf("item %d -> %d \n", counter, node->dataNode);
        counter++;
        node = node->nextNode;
    }

    if (counter > 1)
    {
        ErrorState_local = ES_OK;
    }

    return ErrorState_local;
}

uint32 list_GetLength(struct node *headList)
{
    uint32 counter = 0;
    if (headList != NULL)
    {
        while (headList->nextNode != NULL)
        {
            counter++;
            headList = headList->nextNode;
        }
        counter++;
    }
    else
    {
    }
    return counter;
}

ES_t list_deletFirstNode(struct node **headList)
{
    ES_t ErrorState_local = ES_NOK;
    node_t *tempNode = NULL;
    tempNode = *headList;
    if (*headList != NULL)
    {
        *headList = (*headList)->nextNode;
        free(tempNode);
    }
    else
    {
        ErrorState_local = ES_NULL_POINTER;
    }
    return ErrorState_local;
}

ES_t list_deletLastNode(struct node **headList)
{
    ES_t ErrorState_local = ES_NOK;
    struct node *tempNode = NULL;
    struct node *prevtempNode = NULL;
    prevtempNode = *headList;
    tempNode = prevtempNode->nextNode;
    if (*headList != NULL)
    {
        if (tempNode != NULL)
        {

            while (tempNode->nextNode != NULL)
            {
                prevtempNode = prevtempNode->nextNode;
                tempNode = tempNode->nextNode;
            }
            free(tempNode);
            prevtempNode->nextNode = NULL;
        }
        else // for if there is only one node
        {
            *headList = NULL;
        }
    }

    return ErrorState_local;
}

ES_t list_deletNodeAfter(struct node *headList, uint32 nodeNumber)
{
    ES_t ErrorState_local = ES_NOK;
    node_t *tempNode = NULL;
    node_t *nextTempNode = NULL;
    tempNode = headList;
    nextTempNode = tempNode->nextNode;
    uint32 counter = 1;
    if (headList != NULL && (nodeNumber < list_GetLength(headList)))
    {
        for (counter = 1; counter < nodeNumber; counter++)
        {
            tempNode = tempNode->nextNode;
            nextTempNode = nextTempNode->nextNode;
        }
        tempNode->nextNode = nextTempNode->nextNode;
        free(nextTempNode);
    }

    return ErrorState_local;
}

/*************************************** END DECLERATION ******************************************/
/************************************************************************************************
 * AUTHOR              DATE                    BRIEF
 ************************************************************************************************
 * TAREK ALLAM         2 NOV 2022             write program's functions
 *
 */