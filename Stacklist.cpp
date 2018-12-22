#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *link;
}Snode,*Stacklist;

Stack create_stack(int n)
{
	int i;
	Stacklist Stack;
	Stacklsit p,rear;
	for (i=0;i<n;i++)
	{
		p=(Snode*)malloc(sizeof(Snode));
		cin>>p->data;
		if (Stack==NULL)
		{
			Stack=p;
		}
		else
		{
			p->link=rear;
		}
		rear=p;
	}
	top=rear;
	return Stack;
}

int insert_stack(Stacklist Stack,int item)
{
	Stacklist p;
	p=(Snode*)malloc(sizeof(Snode));
	p->data=item;
	p->link=top;
	top=p;
	return 0;
}

int delete_stack(Stacklist Stack)
{
	Stacklist p;
	p=top;
	top=top->link;
	return 0;
}


