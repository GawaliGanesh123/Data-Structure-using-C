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

int main()
{
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    InsertFirst(&pFirst,111);
    InsertFirst(&pFirst,222);
    InsertFirst(&pFirst,333);

    InsertFirst(&pSecond,444);
    InsertFirst(&pSecond,555);
    InsertFirst(&pSecond,666);

    printf("Before Concating\n");
    Display(pFirst);


    ConcatList(&pFirst, &pSecond);

    printf("\nAfter Concating");

    Display(pFirst);
    Display(pSecond); // kam jhalyavr list empty keli ahe

    return 0;
}