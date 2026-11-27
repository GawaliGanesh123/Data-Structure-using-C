#include<stdio.h>
#include<malloc.h>

# define MAX 5

struct node
{
	int iData;
	struct node *pNext;
};

int CountNodes(struct node *pHead)
{
	int iCount=0;

	while(pHead != NULL)
	{
	   iCount++;
	   pHead= pHead->pNext;
	}

	return iCount;
}

int IsFull(struct node *pHead)
{
	if(CountNodes(pHead)== MAX)
	     return 1;

	return 0;
}

int IsEmpty(struct node *pHead)
{
	if(NULL == pHead)
	   return 1;

	return 0;
}

void Display(struct node *pHead)
{
	if(IsEmpty(pHead))
	{
		printf("\nStack is empty");
		return;
	}

	while(pHead != NULL)
	{
		printf("|%d|->",pHead->iData);
		pHead=pHead->pNext;
	}
}

void Push(struct node **ppHead, int iNo)
{
	struct node *pNewNode=NULL;

	if(IsFull(*ppHead))
	{
	   printf("Stack Overflow");
	   return;
	}

	pNewNode=(struct node*)malloc(sizeof(struct node));

	if(NULL == pNewNode)
	{
		printf("Memory Allocation Failed");
		return;
	}

	pNewNode->iData=iNo;

	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}

int Pop(struct node **ppHead)
{
	int iPoppedData;
	struct node *pTemp=NULL;

	if(IsEmpty(*ppHead))
	{
	  printf("Stack is empty");
	  return -1;
	}

	iPoppedData = (*ppHead)->iData;

	pTemp=*ppHead;

	*ppHead=(*ppHead)->pNext;
	pTemp->pNext = NULL;
	free(pTemp);
	pTemp = NULL; 

	return iPoppedData;
}

void DeleteAll(struct node **ppHead)
{
	struct node *pTemp=NULL;

	while(*ppHead != NULL)
	{
		pTemp = *ppHead;
		*ppHead = pTemp->pNext;
		pTemp->pNext=NULL;
		free(pTemp);
	}
}

int main()
{
	struct node *pStack=NULL;

	Push(&pStack,10);
	Push(&pStack,20);
	Push(&pStack,30);

	Display(pStack);

	printf("\nPopped Data is %d\t",Pop(&pStack));

	Display(pStack);

	if(pStack != NULL)
	{
	  DeleteAll(&pStack);
	  pStack=NULL;
	}

	return 0;
}