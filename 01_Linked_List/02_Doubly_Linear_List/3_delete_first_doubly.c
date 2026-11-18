#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};


void Display(struct node *pHead)
{
    if( NULL == pHead)
    {
        printf("Linked List is empty !!\n");
        return;
    }

    printf("Data from the linked list : \n");

    while(pHead != NULL)
    {
        printf("<-|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    
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

int main()
{
    int  iDelData = 0;
    struct node * pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50);

    printf("Before Deletion\n");

    Display(pFirst);
    

    iDelData = DeleteFirst(&pFirst);

    printf("\nAfter Deletion\n");
    Display(pFirst);
    

    printf("\nDeleted data is : %d\n", iDelData);

    return 0;
}



