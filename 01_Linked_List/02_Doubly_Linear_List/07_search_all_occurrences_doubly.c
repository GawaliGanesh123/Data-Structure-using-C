#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
}; 


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


int SearchAllOccurance(struct node *pHead, int iKey)
{
    int iCount=0;

    while(pHead != NULL)
    {

        if(pHead->iData == iKey)
            iCount++;

        pHead=pHead->pNext;
    }

    return iCount;
}



int main()
{
    int  iRet = 0;
    struct node * pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 60);
    InsertFirst(&pFirst, 70);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 50);


    iRet= SearchAllOccurance(pFirst,50);
        
    printf("Data found : %d times", iRet);
   

    return 0;
}

