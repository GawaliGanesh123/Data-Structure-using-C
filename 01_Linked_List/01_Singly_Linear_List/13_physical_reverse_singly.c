#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;  
};

int countNode(struct node *pHead)
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

    printf("Data from the linked list : \n");

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }

}

void InsertLast(struct node ** ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
    }
}

void PhysicalReverse(struct node **ppHead)
{
  
    struct node *pPrev = NULL;
    struct node *pCurrent = *ppHead;
    struct node * pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *ppHead = pPrev;
}

int main()
{
    
    struct node * pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);

    Display(pFirst);

    PhysicalReverse(&pFirst);

    Display(pFirst);

    return 0;
}
