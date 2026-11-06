#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *PNext;
};

int main()
{
	struct node *PFirst=NULL;

	InsertFirst(&PFirst,100);
	InsertFirst(&PFirst,200);
	InsertFirst(&PFirst,300);
	InsertFirst(&PFirst,400);
	InsertFirst(&PFirst,500);

	Display(PFirst);


	return 0;
}


void InsertFirst(struct node **PPHead, int iNo)
{
	struct node *PNewNode=NULL;

	PNewNode = (struct node *)malloc(sizeof(struct node));

	if(NULL == PNewNode)
	{
	  printf("Memory Allocation Failed");
	  return;
	}

	PNewNode->iData=iNo;

	if(NULL == *PPHead)
	{
	   PNewNode->PNext=NULL;
	   *PPHead=PNewNode;
	   return;
	  
	}

	PNewNode->PNext=*PPHead;
	*PPHead=PNewNode;

}

void Display(struct node *PHead)
{
	if(NULL == PHead)
	{
	   printf("Linked List is Empty");
	   return;
	}

	while(PHead != NULL)
	{
	   printf("|%d|->",PHead->iData);

	   PHead=PHead->PNext;
	}
}



