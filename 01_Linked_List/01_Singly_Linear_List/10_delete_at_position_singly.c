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

    printf("Data from the linked list : \n");

    while(pHead != NULL)
    {
        printf("<-|%d|->", pHead->iData);
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

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iCount=0;
    struct node *pTemp1= NULL;
    struct node *pTemp2=NULL;

    iCount = CountNode(*ppHead);

    if((iPos <=0) || (iPos > iCount))
    {
        printf("Position is invalid");
        return -1;
    }

    if(iPos == 1)
    {
        return DeleteFirst(ppHead);
    }

    if(iPos == iCount)
    {
        return DeleteLast(ppHead);
    }

    iCount=1; 
    pTemp1=*ppHead;

    while(iCount < iPos-1)
    {
        iCount++;
        pTemp1=pTemp1->pNext;
    }

    pTemp2=pTemp1->pNext;
    pTemp1->pNext=pTemp2->pNext;

    iCount= pTemp2->iData;
    pTemp2->pNext=NULL;
    free(pTemp2);

    return iCount;
}




int DeleteFirst(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
    {
        return -1;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    iDelData = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);

    pTemp = NULL;
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

    if(NULL == pTemp->pNext)
    {
        iDelData=pTemp->iData;
        free(pTemp);
        *ppHead=NULL;
    }
    else
    {
        while(pTemp->pNext->pNext != NULL)
        {
            pTemp=pTemp->pNext;
        }

        iDelData=pTemp->pNext->iData;
        free(pTemp->pNext);
        pTemp->pNext=NULL;
    }
    

    pTemp = NULL;
    return iDelData;
}





int main()
{
    int iDelData=0;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,50);

    printf("Before Delete Operation\n");
    Display(pFirst);

    iDelData= DeleteAtPosition(&pFirst,3);

    printf("\nDeleted Data is:%d",iDelData);


    printf("\nAfter Delete Operation\n");
    Display(pFirst);

    


    return 0;
}
