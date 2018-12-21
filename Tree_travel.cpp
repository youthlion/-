#include <iostream>
#include <stdlib.h>
#define M 50
using namespace std;

typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}Tnode,*Tree;


Tree create_tree()
{
	char item;
	Tree T;
	cin>>item;
	if (item=='#')
	{
		T=NULL;
	}
	else
	{
		T=(Tnode*)malloc(sizeof(Tnode));
		T->data=item;
		T->lchild=create_tree();
		T->rchild=create_tree();
	}
	return T;
}

 


void pre_view(Tree T)
{
	Tree Stack[M];
	int top=-1;
	Tree p=T;
	if (T!=NULL)
	{
		do{
			while(p!=NULL)
			{
				Stack[++top]=p;
				cout<<p->data;
				p=p->lchild;
			}
			p=Stack[top--];
			p=p->rchild;
		}while(!(p==NULL && top==-1))
	}
}


void in_view(Tree T)
{
	Tree Stack[M];
	Tree p=T;
	int top=-1;
	if (T!=NULL)
	{
		do
		{
			while(p!=NULL)
			{
				Stack[++top]=p;
				p=p->lchild;
			}
			p=Stack[top--];
			cout<<p->data;
			p=p->rchild;
		}while(!(p==NULL && top=-1))
	}
}


void af_view(Tree T)
{
	Tree Stack[M];
	Tree p=T;
	int top=-1;
	int flag;
	int list[M];
	if (T!=NULL)
	{
		do{
			while(p!=NULL)
			{
				Stack[++top]=p;
				list[top]=0;
				p=p->lchild;
			}
			p=Stack[top];
			flag=list[top--];
			if (flag==1)
			{
				p=Stack[top];
				p=p->rchild;
			}
			else
			{
				cout<<p->data<<" ";
			}
		}while(!(p==NULL && top==-1))
	}
}

int main()
{
	Tree T;
	cout<<"按照前序遍历的顺序输入二叉树的数据"<<endl;
	T=create_tree();
	cout<<"非递归前序遍历输出"<<endl;
	pre_view(T);
	cout<<endl;
	cout<<"非递归中序遍历输出"<<endl;
	in_view(T);
	cout<<endl;
	
}
