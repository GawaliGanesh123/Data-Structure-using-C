#include<stdio.h>
#include<stdlib.h>

struct node
{

    struct node *pNext;
    int iData;
    struct node *pPrev;
};

int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCount = 0;

    if(pHead == NULL)
    {
        return iCount;
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
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Data from the linked list : \n");
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

    if(pNewNode == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;           
    }
    else
    {
        pNewNode->pNext = *ppHead;      
        (*ppHead)->pPrev = pNewNode;   
        *ppHead = pNewNode;
    }       
    (*ppHead)->pPrev = *ppTail;        
    (*ppTail)->pNext = *ppHead;        
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
        return;

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;           
    }
    else
    {
        pNewNode->pPrev = *ppTail;
        (*ppTail)->pNext = pNewNode;
        *ppTail = pNewNode;
    }
    (*ppHead)->pPrev = *ppTail;        
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
        printf("Position is invalid");
        return;
    }

    if(iPos == 1)
        InsertFirst(ppHead, ppTail, iNo);
    else if(iPos == iCount + 1)
        InsertLast(ppHead, ppTail, iNo);
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
            pTemp=pTemp->pNext;
        }

        pNewNode->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pNewNode;
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;
    }
}

int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(*ppHead == NULL)
        return -1;

    iDelData = (*ppHead)->iData;

    if(*ppHead == *ppTail)
    {
        free(*ppHead);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        free((*ppTail)->pNext);

        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(*ppHead == NULL)
        return -1;

    if(*ppHead == *ppTail)
    {
        iDelData = (*ppTail)->iData;
        free(*ppTail);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppTail = (*ppTail)->pPrev;
        iDelData = (*ppTail)->pNext->iData;
        free((*ppTail)->pNext);
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    int iCount = 0, iDelData = 0;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead, *ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("Position is invalid");
        return -1;
    }

    if(iPos == 1)
        return DeleteFirst(ppHead, ppTail);

    else if(iPos == iCount)
        return DeleteLast(ppHead, ppTail);


    else
    {
        pTemp = *ppHead;
        iCount=1;

        while(iCount < iPos)
        {
            iCount++;
            pTemp=pTemp->pNext;
        }

        iDelData = pTemp->iData;
        pTemp->pPrev->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pTemp->pPrev;

        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
        pTemp = NULL;

        return iDelData;
    }
}

int SearchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountPos = 0;

    if(pHead == NULL)
    {
        return 0;
    }

    do
    {
        iCountPos++;
        if(pHead->iData == iKey)
            return iCountPos;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);  

   
    
    return 0;
}

int SearchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountPos = 0, iRetPos = 0;

    if(pHead == NULL)
        return iRetPos;

    do
    {   
        iCountPos++;
        if(pHead->iData == iKey)
            iRetPos = iCountPos;
        
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iRetPos;
}

int SearchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountOcc = 0;

    if(pHead == NULL)
        return iCountOcc;
    
    do
    {
        if(pHead->iData == iKey)
            iCountOcc++;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCountOcc;
}

void ConcatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
    if(*ppHead2 == NULL)
        return;

    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    (*ppHead2)->pPrev = *ppTail1;
    *ppTail1 = *ppTail2;
    (*ppHead1)->pPrev = *ppTail1;
    (*ppTail1)->pNext = *ppHead1;

    *ppHead2 = *ppTail2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead1, *ppTail1);

    if(iPos < 1 || iPos > iCount + 1)
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

    if(iPos == iCount + 1)
    {
        ConcatList(ppHead1, ppTail1, ppHead2, ppTail2);
        return;
    }

    pTemp = *ppHead1;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }

    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = *ppTail2;
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;

    *ppHead2 = *ppTail2 = NULL;
}

void PhysicalReverse(struct node **ppHead, struct node **ppTail)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if(*ppHead == NULL)
        return;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pNext;
        pCurrent = pNext;
    }while(pCurrent != *ppHead);

    *ppHead = *ppTail;
    *ppTail = pCurrent;
}

void ReverseDisplay(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("|%d|->", pTail->iData);
        pTail = pTail->pPrev;
    }while(pTail != pHead->pPrev);
    printf("\n");
}

void DeleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp = NULL;
    pTemp = *ppHead;
    (*ppTail)->pNext = NULL;

    while(pTemp != NULL)
    {
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
        pTemp = *ppHead;
    }
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


