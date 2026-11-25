#include<stdio.h>

#define MAX 5

int g_iTop=-1;


void Push(int *pStack, int iNo)
{
	if(IsFull())
	{
	  printf("Stack Overflow");
	  return;
	}

	pStack[++g_iTop]=iNo;
}

int Pop(int *pStack)
{
	if(IsEmpty())
	{
	  printf("Stack is Empty");
	  return -1;
	}

	return pStack[g_iTop--];
}

int IsFull()
{
	if(g_iTop == MAX-1)
	    return 1;

	    return 0;
}

int IsEmpty()
{
	if(g_iTop == 1)
	    return 1;

	    return 0;
}

void Display(const int *pStack)
{
	int iCounter;

	if(g_iTop == -1)
	{
	   printf("Stack is Empty");
	   return;
	} 

	for(iCounter=0; iCounter<=g_iTop; iCounter++)
	{
	   printf("%d\t",pStack[iCounter]);
	}
	   
}


int main(void)
{
	int Stack[MAX]={0};

	Push(Stack,10);
	Push(Stack,20);
	Push(Stack,30);

	Display(Stack);

	printf("\nPopped data is %d\t",Pop(Stack));

	Display(Stack);

	return 0;
}