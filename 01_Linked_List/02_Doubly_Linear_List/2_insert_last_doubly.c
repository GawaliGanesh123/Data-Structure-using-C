#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};




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
    

        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
        pNewNode->pPrev=pTemp;
    
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

int main()
{
   
    struct node * pFirst = NULL;

    InsertLast(&pFirst, 100);
    InsertLast(&pFirst, 200);
    InsertLast(&pFirst, 300);
    InsertLast(&pFirst, 400);
    InsertLast(&pFirst, 500);

    Display(pFirst);

  

    return 0;
}