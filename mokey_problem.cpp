#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct node
{
	int data;
	struct node *link;
}Lnode,*Linklist;

Linklist create_list(int m)
{
	int i;
	Lnode *rear,*p;
	Linklist list;
	list=NULL;
	for (i=1;i<=m;i++)
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		p->data=i;
		p->link=NULL;
		if (list==NULL)
		{
			list=p;
		}
		else
		{
			rear->link=p;         
		}
		rear=p;
	}
	rear->link=list;
	return list;
}

int main()
{
	int m,n,i=1;
	int j=1;
	Linklist list,head;
	Lnode *temp;
	cout<<"����m��ָ��"<<endl;
	cin>>m;
	list=create_list(m);
	cout<<"����n��ָ:"<<endl;
	cin>>n;
	while(list->link!=list)
	{
		i++;
		head=list;
		list=list->link;
		if (i==n)
		{
			temp=list;
			head->link=list->link;
			list=list->link;
			cout<<"��"<<j++<<"����ȥ����Ϊ"<<temp->data; 
			free(temp);
			i=1;
		}

	}
	cout<<list->data<<endl;
	return 0;
}
