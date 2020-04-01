#include<stdio.h>
#include<stdlib.h>
#include"define.h"

void CreateDLinkList_R(DLinkList *L,int n)		//��ʼ�������ݺ�巨��������
{
	DLinkList p = NULL,r = NULL;
	int i; 
	*L = (DLinkList)malloc(LEN);
	r = *L;
	for(i = 0; i<n;i++)
	{
		p = (DNode *)malloc(LEN);
		printf("Please input people's name:");
		gets(p->data.name);
		printf("Please input people's age:");
		gets(p->data.age);
		m++;
		r->next = p;
		p->prior = r;
		r = p;	
	}
	r->next = NULL;
}

void LinkPrint(DLinkList L)						//��ӡ��������
{
	DLinkList p = L->next;
	while(p)
	{
		printf("name = %s,age = %s\n",p->data.name,p->data.age);
		p = p->next ;
	}
}

int GetElem(DLinkList L,int i,ElemType *e)	//����ض�λ�õ�Ԫ��
{
	int j = 1;
	DLinkList p = NULL;
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

int DLinkInsert(DLinkList *L,int i,ElemType e)	//���ض�λ�ò���Ԫ��
{
	int j;
	DLinkList p = NULL,s = NULL;
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
	s = (DLinkList)malloc(LEN);
	s->data = e;
	s->next = p->next ;
	p->next = s;
	s->prior = p;
	p->next->prior = s;
	m++;
	return 1;
}

int DLinkDelete(DLinkList *L,int i)				//ɾ���ض�λ�õ�Ԫ��
{
	DLinkList p = NULL , q = NULL;
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
	p->next = q->next;
	q->next->prior = p;
	free(q);
	m--;
	return 1;
}

int	ClearList(DLinkList *L)				//�������������
{
	DLinkList p = NULL,q = NULL;
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
	printf("				|                                0.�˳�ϵͳ        |\n");
	printf("				----------------------------------------------------\n");
}