#include"ALL.h"

extern Stack *top;

Stack* Add_new_stack()
{
	Stack *temp = (Stack*)malloc(sizeof(Stack));
	temp->nData = 0;
	temp->Link = NULL;

	return temp;
}

void Push_stack(int item)
{
	Stack *temp = Add_new_stack();
	temp->nData = item;
	temp->Link = top->Link;
	top->Link = temp;
}

int Pop_stack()
{
	Stack *Pop_mem = top->Link;
	int Pop_nData = top->Link->nData;

	top->Link = Pop_mem->Link;
	free(Pop_mem);

	return Pop_nData;
}
int IsEmpty()
{
	return top->Link == NULL;
}
int Count_stack()
{
	int cnt = 0;
	Stack *Count = top->Link;

	while (Count->Link != NULL)
	{
		cnt++;
		Count = Count->Link;
	}
	cnt++;

	return cnt;

}