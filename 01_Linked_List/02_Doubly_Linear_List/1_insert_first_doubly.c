#include<stdio.h>
#include<malloc.h>


struct node
{
	struct node *PPrev;
	int iData;
	struct node *PNext;
};


int main()
{
	struct node *PFirst=NULL;

	InsertFirst(&PFirst,10);
	InsertFirst(&PFirst,20);
	InsertFirst(&PFirst,30);
	InsertFirst(&PFirst,40);
	InsertFirst(&PFirst,50);

	Display(PFirst);
}


void InsertFirst(struct node **PPHead, int iNo)
{
	struct node *PNewNode=NULL;

	PNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL == PNewNode)
	{
       printf("Memory Allocation Failed");
       return;
	}

	PNewNode->iData=iNo;
	PNewNode->PPrev=NULL;

	if(NULL == *PPHead)
	{
	   PNewNode->PNext=NULL;
	   *PPHead=PNewNode;
	   
	   return;
	}


	PNewNode->PNext= *PPHead;
	(*PPHead)->PPrev=PNewNode;
	*PPHead=PNewNode;
}


void Display(struct node *PHead)
{
	 if(NULL == PHead)
	 {
	    printf("Linked list is empty");
	    return;
	 }

	 while(PHead != NULL)
	 {
	    printf("<-|%d|->",PHead->iData);

	    PHead=PHead->PNext;
	 }
}