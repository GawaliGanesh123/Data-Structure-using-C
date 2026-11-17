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


    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("\n");
    
}

int CountNode(struct node *pHead)
{
      int iCount=0;

      if(NULL == pHead)
      {
          return -1;
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

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
        return;
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

void InsertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int iCount=0;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;


    iCount = CountNode(*ppHead);

    if((iPos <=0) || (iPos > iCount + 1))
        {
          printf("Invalid Position");
          return;
        }

    if(iPos == 1)
    {   
        InsertFirst(ppHead, iNo);
        return;
    }
    
    if(iPos == iCount+1)
    {
       InsertLast(ppHead,iNo);
       return;
    }

    else
    {
      pNewNode = (struct node*)malloc(sizeof(struct node));

      if(NULL == pNewNode)
      {
        printf("Memory Allocation Failed");
        return;
      }
       
       pNewNode->iData = iNo;

       iCount=1;
       pTemp=*ppHead;

       while(iCount < iPos-1)
       {
         iCount++;
         pTemp= pTemp->pNext;
       }
       
         pNewNode->pNext = pTemp->pNext;
         pTemp->pNext = pNewNode;
    }
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

int SearchFirstOccurences(struct node *pHead, int iKey)
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

int SearchLastOccurences(struct node *pHead, int iKey)
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


int SearchAllOccurences(struct node *pHead, int iKey)
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

void ConcatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNode(*ppHead1);

    if(iPos <=0  || iPos > iCount + 1)
    {
        printf("Position is Invalid\n");
        return;
    }    

    if(*ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        ConcatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }

     if(iPos == iCount + 1)
     {
         ConcatList(*ppHead1, *ppHead2);
       return;
     }

    pTemp1 = *ppHead1;
    iCount=1;

    while(iCount<iPos-1)
    {
        iCount++;
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = NULL;
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

void ReverseDisplay(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is empty!!\n");
        return;
    }

    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
}


void DeleteAll(struct node **ppHead)
{
    struct node *pTemp= NULL;

    while(*ppHead != NULL)
    {
        pTemp=*ppHead;
        *ppHead=pTemp->pNext;
        pTemp->pNext=NULL;
        free(pTemp);
    }
}

int main()
{
	int iData;
	struct node *pFirst=NULL;
	struct node* pSecond=NULL;

	Display(pFirst);

	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);

	Display(pFirst);

	InsertLast(&pFirst,40);
	InsertLast(&pFirst,50);
	InsertLast(&pFirst,60);

	Display(pFirst);

	InsertAtPosition(&pFirst,20,4);

	Display(pFirst);

	iData=DeleteFirst(&pFirst);
	if(iData != -1)
	   printf("Deleted Data is %d\n",iData);

	 Display(pFirst);


	iData=DeleteLast(&pFirst);
	if(iData != -1)
	   printf("Deleted Data is %d\n",iData);

	Display(pFirst);

	iData=DeleteAtPosition(&pFirst,4);
	if(iData != -1)
	   printf("Deleted Data is %d\n",iData);
	 
    Display(pFirst);

    iData= SearchFirstOccurences(pFirst,20);
    if(iData != 0)
       printf("First Occurrence of %d is at position %d\n",20, iData);

    iData= SearchLastOccurences(pFirst,20);
    if(iData != 0)
       printf("Last Occurrence of %d is at position %d\n",20, iData);  

    iData= SearchAllOccurences(pFirst,20);
    if(iData != 0)
       printf(" %d found %d times\n",20, iData);


    Display(pFirst);
    PhysicalReverse(&pFirst);
    Display(pFirst);

    ReverseDisplay(pFirst);
    Display(pFirst);

    InsertLast(&pSecond,100);   
    InsertLast(&pSecond,200);
    InsertLast(&pSecond,300);

    Display(pFirst);
    Display(pSecond);

    ConcatList(&pFirst, &pSecond);
    Display(pFirst);
    Display(pSecond);

    InsertLast(&pSecond,400);   
    InsertLast(&pSecond,500);
    InsertLast(&pSecond,600);

    Display(pFirst);
    Display(pSecond);
    ConcatAtPosition(&pFirst, &pSecond,4);
    Display(pFirst);
    Display(pSecond);

    if(pFirst != NULL)
    {
       DeleteAll(&pFirst);
       pFirst =NULL;
    }

    if(pSecond != NULL)
    {
       DeleteAll(&pFirst);
       pFirst =NULL;
    }

    Display(pFirst);
    Display(pSecond);

    return 0;

}