
#include<stdio.h>
#include<malloc.h>

#define MAX 5

typedef int BOOL; 

#define TRUE 1
#define FALSE 0

struct node
{
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

BOOL IsEmpty(struct node *pHead)
{
    if(pHead == NULL)
        return TRUE;

    return FALSE;
}

BOOL IsFull(struct node *pHead)
{
    if(MAX == CountNodes(pHead))
        return TRUE;

    return FALSE;
}

void Display(struct node *pHead)
{
    if(IsEmpty(pHead))
    {
        printf("\nStack is Empty\n");
        return;
    }

    printf("\nData from the Stack : \n");

    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }

    printf("NULL\n");
}

void Push(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    if(IsFull(*ppHead))
    {
        printf("\nStack Overflow\n");
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("\nMemory Allocation Failed\n");
        return;
    }

    pNewNode->iData = iNo;

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

int Pop(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(IsEmpty(*ppHead))
    {
        printf("\nStack is Empty\n");
        return -1;
    }

    iDelData = (*ppHead)->iData;

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;

    pTemp->pNext = NULL;

    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int main(void)
{
    struct node *pStack = NULL;
    int iRet = 0;

    Push(&pStack,10);
    Push(&pStack,20);
    Push(&pStack,30);
    Push(&pStack,40);
    Push(&pStack,50);

    Push(&pStack,60);

    Display(pStack);

    iRet = Pop(&pStack);

    if(iRet != -1)
        printf("\nPopped Data is : %d\n",iRet);

    Display(pStack);

    printf("\nCount of Nodes is : %d\n",CountNodes(pStack));

    return 0;
}



