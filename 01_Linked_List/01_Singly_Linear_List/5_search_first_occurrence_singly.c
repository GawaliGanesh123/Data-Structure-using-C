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


int SearchFirstOccurance(struct node *pHead, int iKey)
{
    int iPos=0;

    while(pHead != NULL)
    {
        iPos++;

        if(pHead->iData == iKey)
            return iPos;

        pHead=pHead->pNext;
    }
}




int main()
{
    int  iPos= 0;
    struct node * pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 50);

    

    iPos= SearchFirstOccurance(pFirst,20);
        
  
    printf("Data found at index : %d", iPos);
    

    return 0;
}