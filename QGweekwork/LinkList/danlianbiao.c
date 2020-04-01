#include<stdio.h>
#include<stdlib.h>
#include"define.h"



void CreateList_R(LinkList *L,int n)	//��ʼ�������ݺ�巨��������
{
	LinkList p = NULL , r = NULL;
	int i;
	*L = (LinkList)malloc(LEN);
	r = *L;
	for(i = 0;i<n;i++)
	{
		p = (LNode *)malloc(LEN);
		printf("Please input people's name:");
		gets(p->data.name);
		printf("Please input people's age:");
		gets(p->data.age);
		r ->next = p;
		r = p;
	}
	r->next = NULL;
}

void LinkPrint(LinkList L)						//��ӡ��������
{
	LinkList p = L->next;
	while(p)
	{
		printf("name = %s,age = %s\n",p->data.name,p->data.age);
		p = p->next ;
	}
}

int GetElem(LinkList L,int i,ElemType *e)			//����ض�λ�õ�Ԫ��
{
	int j = 1;
	LinkList p = NULL;
	p = L->next;
	while(p && j<i)
	{
		p = p->next ;
		++j;
	}
	if(!p || j>i)			// iֵ���Ϸ�����i>n��i<0
		return 0;
	*e = p->data;
	return 1;
}

int LinkInsert(LinkList *L,int i,ElemType e)		//���ض�λ�ò���Ԫ��
{
	int j;
	LinkList p = NULL,s = NULL;
	p = *L;
	j = 1;
	while(p && j<i)
	{
		p = p->next ;
		++j;
	}
	if(!p || j>i)
	{
		return 0;
	}
	s = (LinkList)malloc(LEN);
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}	

int LinkDelete(LinkList *L,int i)				//ɾ���ض�λ�õ�Ԫ��
{
	LinkList p = NULL , q = NULL;
	int j;
	p = *L;
	j = 1;
	while(p->next && j<i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i)
	{
		return 0;
	}
	q = p->next ;
	p->next = q->next ;
	free(q);
	return 1;
}

int	ClearList(LinkList *L)				//�������������
{
	LinkList p = NULL,q = NULL;
	p = (*L)->next;
	while(p)
	{
		q = p->next ;
		free(p);
		p = q;
	}
	(*L)->next  = NULL;
	return 1;
}


void Showmenu()				//��ӡ�˵�
{
	system("cls");
	printf("				--------------------------------------------------\n");
	printf("				|       1.��������               2.��ӡ����    |\n");
	printf("				|       3.��ý��               4.���ӽ��        |\n");
	printf("				|       5.ɾ�����               6.�������        |\n");
	printf("				|       7.�����ż����           0.�˳�ϵͳ        |\n");
	printf("				----------------------------------------------------\n");
}

void Enchange(LinkList *L)			//����ż������������
{
	ElemType temp;
	LinkList p = (*L)->next;
	while(p)
	{
		if(p->next)
		{
			temp = p->data;
			p->data = p->next->data;
			p->next->data = temp;
			p = p->next->next;
		}
		else
		{
			break;
		}
		
	}
}