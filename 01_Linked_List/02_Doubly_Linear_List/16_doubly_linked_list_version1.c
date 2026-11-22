#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;   
};

int CountNodes(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

void Display(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is empty !!\n");
        return;
    }

    printf("NULL");
    while(pHead != NULL)
    {
        printf("<-|%d|<->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
   
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

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(NULL == *ppHead)
    {
        pNewNode->pPrev = NULL;
        *ppHead = pNewNode;
        return;
    }
    
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        { 
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;
    
}

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount = 0;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("Invalid Position");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(ppHead, iNo);
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

int DeleteFirst(struct node **ppHead)
{
    int iDelData = 0;

    if(NULL == *ppHead)
    {
        return -1;
    }
     
     iDelData=(*ppHead)->iData;

     if(NULL == (*ppHead)->pNext)
     {
      free(*ppHead);
      *ppHead=NULL;
     }
     else
     {
        *ppHead=(*ppHead)->pNext;
        (*ppHead)->pPrev->pNext= NULL;
        free((*ppHead)->pPrev);
        (*ppHead)->pPrev=NULL;
     }

   
    return iDelData;
}

int DeleteLast(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
    {
        return -1;
    }

    pTemp = *ppHead;

    if(NULL == (*ppHead)->pNext)
    {
        *ppHead=NULL;
    }
    
    else
    {
    
        while(pTemp->pNext != NULL)
        {
            pTemp=pTemp->pNext;
        }

        pTemp->pPrev->pNext=NULL;
        pTemp->pPrev=NULL;
    }

    iDelData=pTemp->iData;
    free(pTemp);
    
    pTemp = NULL;
    return iDelData;
   
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCount=0;
    struct node *pTemp=NULL;

    iCount=CountNodes(*ppHead);

    if(iPos <=0 || iPos > iCount)
    {
        printf("Position is Invalid");
        return -1;
    }

    if(1 == iPos)
        return DeleteFirst(ppHead);

    if(iPos == iCount)
    {
        return DeleteLast(ppHead);
    }
 
    iCount=1;
    pTemp=*ppHead;

    while(iCount<iPos)
    {
        iCount++;
        pTemp=pTemp->pNext;
    }

    pTemp->pPrev->pNext=pTemp->pNext;
    pTemp->pNext->pPrev=pTemp->pPrev;

    pTemp->pNext= pTemp->pPrev=NULL;
    iCount=pTemp->iData;
    free(pTemp);

    return iCount;
}

int SearchFirstOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0;

    while(pHead != NULL)
    {   
        iPos++;
        if(pHead->iData == iKey)
        {
            return iPos;
        }
        pHead = pHead->pNext;
    }
    
   
    return iPos;
}

int SearchLastOccurrence(struct node *pHead, int iKey)
{
    int iPos = 0, iLastPos = 0;

    while(pHead != NULL)
    {   
        iPos++;
        if(pHead->iData == iKey)
        {
            iLastPos = iPos;
        }
        pHead = pHead->pNext;
    }
    return iLastPos;
}

int SearchAllOccurrences(struct node *pHead, int iKey)
{
    int iCount = 0;

    while(pHead != NULL)
    {   
        if(pHead->iData == iKey)
        {
            iCount++;
        }
        pHead = pHead->pNext;   
    }
    return iCount;
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
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead1);

    if(iPos <=0  || iPos > iCount + 1)
    {
      printf("Position Invalid\n");
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

    pTemp1 = *ppHead1;
    iCount=1;

    while(iCount < iPos-1)
    {
      iCount++;
      pTemp1=pTemp1->pNext;
    }

    pTemp2=*ppHead2;

    while(pTemp2->pNext != NULL)
      pTemp2=pTemp2->pNext;

   pTemp2->pNext=pTemp1->pNext;
   pTemp1->pNext->pPrev=pTemp2;
   pTemp1->pNext=*ppHead2;
   (*ppHead2)->pPrev=pTemp1;

   *ppHead2=NULL;
}

void PhysicalReverse(struct node **ppHead)
{
    struct node *pCurrent = *ppHead;
    struct node *pTemp =NULL;

    if((*ppHead)->pNext == NULL)
      return;

    while(pCurrent != NULL)
    {
        pTemp = pCurrent->pPrev;
        pCurrent->pPrev = pCurrent->pNext;
        pCurrent->pNext= pTemp;
        pCurrent = pCurrent->pPrev;
    }

    
    *ppHead = pTemp->pPrev;
}

void ReverseDisplay(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    while(pHead->pNext != NULL)
    {
        pHead = pHead->pNext;
    }

    while(pHead != NULL)
    {
        printf("<-|%d|->", pHead->iData);
        pHead = pHead->pPrev;
    }
   
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp =NULL;

    while(*ppHead != NULL)
    {
        pTemp=*ppHead;
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
    }
   
}

int main()
{
    int iData = 0;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);
    
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    Display(pFirst);

    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);

    Display(pFirst);

    InsertAtPosition(&pFirst, 20, 4);           

    Display(pFirst);

    iData = DeleteFirst(&pFirst);
    if(iData != -1)
    {
        printf("Deleted data is %d\n", iData);
    }

    Display(pFirst);

    iData = DeleteLast(&pFirst);
    if(iData != -1)
    {
        printf("Deleted data is %d\n", iData);
    }

    Display(pFirst);

    iData = DeleteAtPosition(&pFirst, 4);
    if(iData != -1)
    {
        printf("Deleted data is %d\n", iData);
    }

    Display(pFirst);

    iData = SearchFirstOccurrence (pFirst, 20);
    if(iData != 0)
    {
        printf("First occurrence of %d is at position %d\n", 20, iData);
    }

    iData = SearchLastOccurrence(pFirst, 20);
    if(iData != 0)
    {
        printf("Last occurrence of %d is at position %d\n", 20, iData);
    }

    iData = SearchAllOccurrences(pFirst, 20);
    printf("%d found %d times\n", 20, iData);

    iData = CountNodes(pFirst);
    printf("Total count is %d\n", iData);

    printf("Before Reverse:\n");
    Display(pFirst);
    PhysicalReverse(&pFirst); 
    printf("After Reverse\n"); 
    Display(pFirst);

    ReverseDisplay(pFirst);
    Display(pFirst);

    
    InsertLast(&pSecond, 100);
    InsertLast(&pSecond, 200);
    InsertLast(&pSecond, 300);
    
    Display(pFirst);
    Display(pSecond);

    ConcatList(&pFirst, &pSecond);

    Display(pFirst);
    Display(pSecond);

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);

    Display(pFirst);
    Display(pSecond);
    ConcatAtPosition(&pFirst, &pSecond, 4);
    Display(pFirst);
    Display(pSecond);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    if(pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }

    Display(pFirst);
    Display(pSecond);

    return 0;
}