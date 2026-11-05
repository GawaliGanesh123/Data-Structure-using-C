#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};


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


int SearchLastOccurance(struct node *pHead, int iKey)
{
    int iPos=0;
    int iLastPos=0;

    while(pHead != NULL)
    {
        iPos++;

        if(pHead->iData == iKey)
            iLastPos=iPos;

        pHead=pHead->pNext;
    }

    return iLastPos;
}




int main()
{
    int  iPos= 0;
    struct node * pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 70);

    

    iPos= SearchLastOccurance(pFirst,30);
        
    
    printf("Data found at Last index : %d", iPos);
    

    return 0;
}