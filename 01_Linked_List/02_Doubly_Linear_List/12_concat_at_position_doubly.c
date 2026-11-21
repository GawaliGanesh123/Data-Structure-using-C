#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pNext;
    int iData;
    struct node *pPrev;
};


int CountNode(struct node *pHead)
{
      int iCount=0;

      if(NULL == pHead)
      {
          return;
      }

      while(pHead != NULL)
      {
        iCount++;
        pHead= pHead->pNext;
      }

      return iCount;
}

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



void ConcatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(*ppHead2 == NULL)
    {
        return;
    }
    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }
    
    pTemp = *ppHead1;

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNode(*ppHead1);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(*ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        ConcatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }

    pTemp1 = *ppHead1;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext->pPrev = pTemp2;
    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1; 

    *ppHead2= NULL;
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
    struct node *pSecond = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 11);
    InsertFirst(&pFirst, 12);
    InsertFirst(&pFirst, 13);
    InsertFirst(&pFirst, 14);

    InsertFirst(&pSecond,15);
    InsertFirst(&pSecond,16);
    InsertFirst(&pSecond,17); 

    ConcatAtPosition(&pFirst, &pSecond, 4);

    Display(pFirst);

    if(NULL != pFirst)
    {
        DeleteAll(&pFirst);
        pFirst=NULL;
    }

    return 0;
}

