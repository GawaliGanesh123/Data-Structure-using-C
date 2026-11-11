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




int CountNodes(struct node *pHead)
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


int main()
{
    int  iCount= 0;
    struct node * pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50);

    

    iCount= CountNodes(pFirst);
        

    printf("\nTotal Nodes are : %d\n", iCount);

    return 0;
}
