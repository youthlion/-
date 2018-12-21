#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	float xi;
	int zhi;
	struct node *link;
}Lnode,*Linklist;

Linklist create_list(int n)
{
	int i;
	Lnode *p,*rear;
	Linklist list;
	list=NULL;
	for (i=1;i<=n+1;i++)
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		p->zhi=n+1-i;
		cout<<"输入第"<<i<<"个系数："<<endl;
		cin>>p->xi;
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
	return list;
}

void disp(Linklist list)
{
	int i,n;
	Linklist p;
	p=list;
	n=list->zhi;
	for (i=0;i<n+1;i++)
	{
		if (p->zhi>0)
		{
			if (p->xi>0)
			{
				cout<<"+"<<p->xi<<"*x^"<<p->zhi;
			}
			else if(p->xi==0)
			{
			}
			else
			{
				cout<<p->xi<<"*x^"<<p->zhi;
			}
		}
		else
		{
			if (p->xi>0)
			{
				cout<<"+"<<p->xi<<endl;
			}
			else if (p->xi==0)
			{
				cout<<endl;
			}
			else
			{
				cout<<p->xi<<endl;
			}
		}
		p=p->link;
	}
}

Linklist addlist(Linklist list1,Linklist list2)
{
	int i;
	int n1,n2;
	Linklist temp;
	if (list1->zhi>list2->zhi)
	{
		n1=list1->zhi-list2->zhi;
		n2=list2->zhi;
		temp=list1;
		for (i=0;i<n1;i++)
		{
			list1=list1->link;
		}
		for (i=0;i<n2+1;i++)
		{
			list1->xi=list1->xi+list2->xi;
			list1=list1->link;
			list2=list2->link;
		}
	}
	else
	{
		n1=list2->zhi-list1->zhi;
		n2=list1->zhi;
		temp=list2;
		for (i=0;i<n1;i++)
		{
			list2=list2->link;
		}
		for (i=0;i<n2;i++)
		{
			list2->xi=list1->xi+list2->xi;
			list1=list1->link;
			list2=list2->link;
		}
	}
	return temp;
}


Linklist sublist(Linklist list1,Linklist list2)
{
	int i;
	int n1,n2;
	Linklist temp;
	if (list1->zhi>list2->zhi)
	{
		n1=list1->zhi-list2->zhi;
		n2=list2->zhi;
		temp=list1;
		for (i=0;i<n1;i++)
		{
			list1=list1->link;
		}
		for (i=0;i<n2+1;i++)
		{
			list1->xi=list1->xi-list2->xi;
			list1=list1->link;
			list2=list2->link;
		}
	}
	else
	{
		n1=list2->zhi-list1->zhi;
		n2=list1->zhi;
		temp=list2;
		for (i=0;i<n1;i++)
		{
			list2->xi=-list2->xi;
			list2=list2->link;
		}
		for (i=0;i<n2+1;i++)
		{
			list2->xi=list1->xi-list2->xi;
			list1=list1->link;
			list2=list2->link;
		}
	}
	return temp;
}


int main()
{
	int n1,n2;
	Linklist list1,list2,list3,list4;
	cout<<"输入第一个一元多项式的指数最大值："<<endl;
	cin>>n1;
	list1=create_list(n1);
	cout<<"第一个一元多项式的输出："<<endl;
	disp(list1); 
	cout<<"输入第二个一元多项式的指数最大值："<<endl;
	cin>>n2;
	list2=create_list(n2);
	cout<<"第二个一元多项式的输出："<<endl;
	disp(list2); 
	cout<<"输出两个一元多项式："<<endl;
	disp(list1);
	disp(list2);
	list3=addlist(list1,list2);
	cout<<"输出两个一元多项式的和："<<endl;
	disp(list3);
	cout<<"输出两个一元多项式："<<endl;
	disp(list1);
	disp(list2);
	list4=sublist(list1,list2);
	cout<<"输出两个一元多项式的差："<<endl;
	disp(list4);
	return 0;
}
