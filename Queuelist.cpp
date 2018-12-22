#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *link;
}Qnode,*Queue;

Queue create_queue(int n)
{
	int i;
	Queue front,p,rear;
	Queue Q;
	for (i=0;i<n;i++)
	{
		p=(Qnode*)malloc(sizeof(Qnode));
		cin>>p->data;
		if (Q==NULL)
		{
			Q=p;
			front=p;
		}
		else
		{
			rear->link=p;
		}
		rear=p;
	}
	return Q;
}


