#include <iostream>
#include <stdlib.h>
#define Maxsize 50
using namespace std;

//��ջ��˳��洢�ṹ�������������ʽ��topָ�����һ��Ԫ�ص��±�ֵ��

void init_stack(int &top)                 //ʹ�����÷������ݲ������������ڵ�top�ı�ʱ��topֵ���Ÿı� 
{
	top=-1;
}

int* create_stack(int n,int &top)
{
	int i;
	int stack[Maxsize];
	for (i=0;i<n;i++)
	{
		cin>>stack[++top];
	}
	return stack;
}

int insert_stack(int *stack,int i,int item)
{
	int j;
	if (top==Maxsize-1)
	{
		return -1;
	}
	else
	{
		for (j=top;j>=i-1;j--)
		{
			stack[j+1]=stack[j];
		}
		stack[i-1]=item;
		top++;
		return 0;
	}
}

int delete_stack(int stack[],int &top)
{
	if (top==-1)
	{
		return 0;
	}
	else
	{
		int item;
		item=stack[top--];
	}
}

void disp(int stack[],int top)
{
	int i;
	if (top==-1)
	{
		return -1;
	}
	else
	{
		for (i=0;i<=top;i++)
		{
			cout<<stack[i];
		}
	}
}

















