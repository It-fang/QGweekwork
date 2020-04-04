#include<stdio.h>
#include<stdlib.h>
#include"define.h"



int CreateList_R(LinkList *L,int n)	//��ʼ�������ݺ�巨��������
{
	LinkList p = NULL , r = NULL;
	int i;
	if(*L)
	{
		return 0;
	}
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
	return 1;
}

void LinkPrint(LinkList L)						//��ӡ��������
{
	LinkList p = L->next;
	if(!p)
	{
		printf("LinkList is Empty");
	}
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
	printf("				|       1.��������               2.��ӡ����        |\n");
	printf("				|       3.��ý��               4.���ӽ��        |\n");
	printf("				|       5.ɾ�����               6.�������        |\n");
	printf("				|       7.�����ż����           8.����ָ�����е�  |\n");
	printf("				|                                0.�˳�ϵͳ        |\n");
	printf("				----------------------------------------------------\n");
}

void Enchange(LinkList *L)			//����ż������������
{
	LinkList p = (*L)->next;
	while(p&&p->next)
	{	

		if(p == (*L)->next)
		{
			(*L)->next = p->next;
			p->next = p->next->next;
			(*L)->next->next = p;
		}
		else
		{
			p->next = p->next->next;
			p->next->next=p;
		}

		p = p->next;		
	}
}

void FindMidpoint(LinkList L,ElemType *e)			// ���ÿ���ָ��Ѱ���е�
{
	LinkList p1 = NULL,p2 = NULL;
	p1 = p2 = L->next;
	while(p2&&p2->next)
	{
		p2 = p2->next->next;
		p1=p1->next;
	}
	*e = p1->data;
}