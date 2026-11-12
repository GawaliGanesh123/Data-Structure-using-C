#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
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
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    
}

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

void InsertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
      printf("Memory Allocation Failed");
      return;
    }

    pNewNode->iData = iNo;
    
    if(NULL == *ppHead)
    {
       pNewNode->pNext=NULL;
       *ppHead=pNewNode;
       return;
      
    }

    pNewNode->pNext=*ppHead;
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
    *ppHead2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNode(*ppHead1);

    if(iPos <=0  || iPos > iCount + 1)
    {
        printf("Position is Invalid\n");
        return;
    }    

    if(*ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        ConcatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }

     if(iPos == iCount + 1)
     {
         ConcatList(*ppHead1, *ppHead2);
       return;
     }

    pTemp1 = *ppHead1;
    iCount=1;

    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = NULL;
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp= NULL;

    while(*ppHead != NULL)
    {
        pTemp=*ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        free(pTemp);
    }
}

int main()
{

    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    InsertFirst(&pFirst,15);
    InsertFirst(&pFirst,25);
    InsertFirst(&pFirst,35);

    InsertFirst(&pSecond,45);
    InsertFirst(&pSecond,55);
    InsertFirst(&pSecond,65);


     Display(pFirst);

    ConcatAtPosition(&pFirst, &pSecond, 3);

    Display(pFirst);

    if(NULL != pFirst)
    {
       DeleteAll(&pFirst);
       pFirst=NULL;
    }

    return 0;
}