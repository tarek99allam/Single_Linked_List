/* ********************************************************************************************
/* @name     : QUEUE.H
/* @brief    : DECLERATIONS
/* @author   : TAREK ALLAM
/***********************************************************************************************/

/*************************************** START GUARD ****************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
/*************************************** END GUARD ******************************************/

/*************************************** START INCLUDES ****************************************/
#include "errorState.h"
#include "stdTypes.h"
/*************************************** END INCLUDES ******************************************/

/*************************************** START STRUCTS ****************************************/

typedef struct node
{
    uint32 dataNode;
    struct node *nextNode;
} node_t;

/*************************************** END STRUCTS ******************************************/

/*************************************** START DECLERATION ************************************/
ES_t list_insertNodeEnd(struct node **headList, uint32 nodeData);

ES_t list_insertNodeBegging(struct node **headList, uint32 nodeData);

ES_t list_insertNodeAfter(struct node *headList, uint32 nodeData, uint32 nodeNumber);

ES_t list_showItems(struct node *node);

ES_t list_GetLength(struct node *headList);

ES_t list_deletFirstNode(struct node **headList);

ES_t list_deletLastNode(struct node **headList);

ES_t list_deletNodeAfter(struct node *headList, uint32 nodeNumber);

/*************************************** END DECLERATION ******************************************/

#endif // !_QUEUE_H_

/**************************************************************************************************
 * AUTHOR              DATE                    BRIEF
 **************************************************************************************************
 * TAREK ALLAM         2 NOV 2022             write declertaions
 *
 */