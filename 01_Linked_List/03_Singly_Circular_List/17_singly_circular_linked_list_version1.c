#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCount = 0;

    if(pHead == NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCount;
}

void Display(struct node *pHead, struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    printf("\n");
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation Failed");
        return;
    }

    pNewNode->iData = iNo;

    if(NULL == *ppHead)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;             
        (*ppTail)->pNext = *ppHead;     

        return;
    }

    pNewNode->pNext = *ppHead;          
    *ppHead = pNewNode;                 
    (*ppTail)->pNext = *ppHead;         
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode)
    {
        printf("Memory allocation Failed");
        return;
    }

    pNewNode->iData = iNo;

    if(NULL == *ppHead)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;             
        (*ppTail)->pNext = *ppHead;     

        return;
    }

    (*ppTail)->pNext = pNewNode;       
    *ppTail = pNewNode;                
    (*ppTail)->pNext = *ppHead;        
}

void InsertAtPosition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
    int iCount = 0;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead, *ppTail);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(ppHead, ppTail, iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(ppHead, ppTail, iNo);
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
        pTemp->pNext = pNewNode;
    }
}

int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(NULL == *ppHead)
    {
        return -1;
    }

    iDelData = (*ppHead)->iData;

    if(*ppHead == *ppTail)                  
    {   
        (*ppHead)->pNext = NULL;            
        free(*ppHead);                      
        *ppHead = *ppTail = NULL;           

    }
    else
    {

       *ppHead = (*ppHead)->pNext;          
       (*ppTail)->pNext->pNext = NULL;      
       free((*ppTail)->pNext);              
       (*ppTail)->pNext = *ppHead; 

    }            

    return iDelData;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
    {
        return -1;
    }

   
    pTemp = *ppHead;

    while(pTemp->pNext != *ppTail)         
    {
        pTemp = pTemp->pNext;
    }

    iDelData = (*ppTail)->iData;
    (*ppTail)->pNext = NULL;               
    free(*ppTail); 
    

    if(*ppHead == *ppTail)                 
    {    
       
       *ppHead = *ppTail = NULL;          

    }

    else
    {
       *ppTail = pTemp;                       
       (*ppTail)->pNext = *ppHead;   
    }

    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    int iCount = 0; 
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead, *ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("Position is invalid");
        return -1;
    }

    if(iPos == 1)
        return DeleteFirst(ppHead, ppTail);

    if(iPos == iCount)
        return DeleteLast(ppHead, ppTail);

    iCount=1;
    pTemp1 = *ppHead;

    while(iCount < iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }

    pTemp2 = pTemp1->pNext;
    pTemp1->pNext = pTemp2->pNext;

    iCount = pTemp2->iData;
    pTemp2->pNext = NULL;
    free(pTemp2);

    return iCount;
}

int SearchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iPosition = 0;

    if(pHead == NULL)
        return 0;

    do
    {
        iPosition++;
        if(pHead->iData == iKey)
            break;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);


    return iPosition;
}

int SearchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iPosition = 0, iRetPosition = 0;

    if(pHead == NULL)
        return 0;

    do
    {
        iPosition++;

        if(pHead->iData == iKey)
            iRetPosition = iPosition;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iRetPosition;
}

int SearchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
    int iCounter = 0;

    if(pHead == NULL)
        return 0;
    
    do
    {
        if(pHead->iData == iKey)
            iCounter++;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCounter;
}

void ConcatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
    if( NULL == *ppHead2)
        return;

    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    *ppTail1 = *ppTail2;
    (*ppTail1)->pNext = *ppHead1;

    *ppHead2 = *ppTail2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
    int iCount = 0;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead1, *ppTail1);

    if(iPos <=0  || iPos > iCount + 1)
    {
        printf("Position is invalid\n");
        return;
    }

    if(ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        ConcatList(ppHead2, ppTail2, ppHead1, ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;

        return;
    }


    if(iPos == iCount +1)
    {
       pTemp=*ppTail1;
       *ppTail1=*ppTail2;
    }

    else
    {
       pTemp = *ppHead1; 
       iCount=1;

       while(iCount<iPos -1)
       {
          iCount++;
          pTemp=pTemp->pNext;
       }
    }

      (*ppTail2)->pNext = pTemp->pNext;
      pTemp->pNext = *ppHead2;

      *ppHead2= *ppTail2=NULL;


}

void PhysicalReverse(struct node **ppHead, struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;


    if(*ppHead == NULL)
        return;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;

    }while(pCurrent != *ppHead);

    *ppHead = *ppTail;
    *ppTail = pCurrent;
}

void ReverseDisplay(struct node *pHead, struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("Linked list is empty");
        return;
    }

    PhysicalReverse(&pHead, &pTail);
    Display(pHead, pTail);
    PhysicalReverse(&pHead, &pTail);
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return;

    (*ppTail)->pNext = NULL;

    while( NULL != *ppHead)
    {
        pTemp = *ppHead;

        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        pTemp->pPrev=NULL;
        free(pTemp);
    }
      ppTail=NULL;
}

int main()
{

    int iData = 0;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;

    Display(pFirst, pLast);
    
    InsertFirst(&pFirst, &pLast, 30);
    InsertFirst(&pFirst, &pLast, 20);
    InsertFirst(&pFirst, &pLast, 10);

    Display(pFirst, pLast);

    InsertLast(&pFirst, &pLast, 40);
    InsertLast(&pFirst, &pLast, 50);
    InsertLast(&pFirst, &pLast, 60);

    Display(pFirst, pLast);

    InsertAtPosition(&pFirst, &pLast, 20, 4);           

    Display(pFirst, pLast);

    iData = DeleteFirst(&pFirst, &pLast);
    if(iData != -1)
    {
        printf("Deleted data is %d\n", iData);
    }

    Display(pFirst, pLast);

    iData = DeleteLast(&pFirst, &pLast);
    if(iData != -1)
    {
        printf("Deleted data is %d\n", iData);
    }

    Display(pFirst, pLast);

    iData = DeleteAtPosition(&pFirst, &pLast, 4);
    if(iData != -1)
    {
        printf("Deleted data is %d\n", iData);
    }

    Display(pFirst, pLast);

    iData = SearchFirstOccurrence (pFirst, pLast, 20);
    if(iData != 0)
    {
        printf("First occurrence of %d is at position %d\n", 20, iData);
    }

    iData = SearchLastOccurrence(pFirst, pLast, 20);
    if(iData != 0)
    {
        printf("Last occurrence of %d is at position %d\n", 20, iData);
    }

    iData = SearchAllOccurrences(pFirst, pLast, 20);
    printf("%d found %d times\n", 20, iData);

    Display(pFirst, pLast);
    PhysicalReverse(&pFirst, &pLast);
    Display(pFirst, pLast);

    ReverseDisplay(pFirst, pLast);
    Display(pFirst, pLast);


    InsertLast(&pFirst1, &pLast1, 100);
    InsertLast(&pFirst1, &pLast1, 200);
    InsertLast(&pFirst1, &pLast1, 300);

    Display(pFirst1, pLast1);

    ConcatList(&pFirst, &pLast, &pFirst1, &pLast1);
    Display(pFirst, pLast);
    Display(pFirst1, pLast1);

    InsertLast(&pFirst1, &pLast1, 400);
    InsertLast(&pFirst1, &pLast1, 500);
    InsertLast(&pFirst1, &pLast1, 600);

    Display(pFirst, pLast);
    Display(pFirst1, pLast1);
    ConcatAtPosition(&pFirst, &pLast, &pFirst1, &pLast1, 4);
    Display(pFirst, pLast);
    Display(pFirst1, pLast1);

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst, &pLast);
        pFirst = NULL;
    }

    if(pFirst1 != NULL)
    {
        DeleteAll(&pFirst1, &pLast1);
        pFirst1 = NULL;
    }

    Display(pFirst, pLast);
    Display(pFirst1, pLast1);

    return 0;
}