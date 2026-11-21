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

    iCount=CountNode(*ppHead);

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

    pTemp->pNext= NULL;
    pTemp->pPrev=NULL;
    iCount=pTemp->iData;
    free(pTemp);

    return iCount;

}




int main()
{
    int iDelData=0;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst,101);
    InsertFirst(&pFirst,201);
    InsertFirst(&pFirst,301);
    InsertFirst(&pFirst,401);
    InsertFirst(&pFirst,501);

    printf("Before Delete Operation\n");
    Display(pFirst);

    iDelData= DeleteAtPosition(&pFirst,4);

    printf("\nDeleted Data is:%d",iDelData);

    printf("\nAfter Delete Operation\n");
    Display(pFirst);

    


    return 0;
}