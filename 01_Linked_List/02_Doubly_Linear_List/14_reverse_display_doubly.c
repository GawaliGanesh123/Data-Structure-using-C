#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pNext;
    int iData;
    struct node *pPrev;
};



void Display(struct node *pHead)
{
    if( NULL == pHead)
    {
        printf("Linked List is empty \n");
        return;
    }

    printf("\nData from the linked list : \n");

    while(pHead != NULL)
    {
        printf("<-|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    
}


void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode=NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
       printf("Memory Allocation Failed");
       return;
    }

    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;

    if(NULL == *ppHead)
    {
       pNewNode->pNext=NULL;
       *ppHead=pNewNode;
       return;
    }


    pNewNode->pNext= *ppHead;
    (*ppHead)->pPrev=pNewNode;
    *ppHead=pNewNode;
}

void DisplayReverse(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while(pHead->pNext != NULL)
    {
        pHead = pHead->pNext;
    }

    while(pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pPrev;
    }
    
}



void DeleteAll(struct node **ppHead)
{
    struct node *pTemp= NULL;

    while(*ppHead != NULL)
    {
        pTemp=*ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        pTemp->pPrev=NULL;
        free(pTemp);
    }
}

int main()
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50); 
     
    printf("Before\n");
    Display(pFirst);

    printf("\nAfter\n");
    DisplayReverse(pFirst);

    if(NULL != pFirst)
    {
       DeleteAll(&pFirst);
       pFirst=NULL;
    }

    return 0;
}