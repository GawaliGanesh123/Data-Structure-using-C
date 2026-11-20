#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
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

    printf("Data from the linked list : \n");

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


void InsertLast(struct node ** ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));
     
    if(NULL == pNewNode)
    {
        printf("Memory Allocation failed");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(NULL == *ppHead)
    {
        pNewNode->pPrev=NULL;
        *ppHead=pNewNode;
        return;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
        pTemp->pPrev=pTemp;
    }
}


void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount=0;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNode(*ppHead);

    if((iPos <=0) || (iPos > iCount + 1))
        {
          printf("Invalid Position");
          return;
        }

    if(iPos == 1)
    {   
        InsertFirst(ppHead, iNo);
        return;
    }
    
    if(iPos == iCount+1)
    {
       InsertLast(ppHead,iNo);
       return;
    }

    else
    {
      pNewNode = (struct node*)malloc(sizeof(struct node));

      if(NULL == pNewNode)
      {
        printf("Memory Allocation Failed");
        return;
      }
       
       pNewNode->iData = iNo;

       iCount=1;
       pTemp=*ppHead;

       while(iCount < iPos-1)
       {
         iCount++;
         pTemp= pTemp->pNext;
       }
       
         pNewNode->pNext = pTemp->pNext;
         if(pTemp->pNext != NULL)
         {
            pTemp->pNext->pPrev = pNewNode;
         }

         pTemp->pNext = pNewNode;
         pNewNode->pPrev=pTemp;
    }
  }



int main()
{
    struct node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,50);

    printf("Before\n");
    Display(pFirst);

    InsertAtPosition(&pFirst,500,2);

    printf("\nAfter\n");
    Display(pFirst);

    


    return 0;
}