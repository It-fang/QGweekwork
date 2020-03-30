#include<stdio.h>
#include<stdlib.h>
#include"define.h"

void CreateList_R(LinkList *L,int n);		//��ʼ�������ݺ�巨��������
void LinkPrint(LinkList L);					//��ӡ��������
int GetElem(LinkList L,int i,ElemType *e);	//����ض�λ�õ�Ԫ��
int LinkInsert(LinkList *L,int i,ElemType e);	//���ض�λ�ò���Ԫ��
int LinkDelete(LinkList *L,int i);				//ɾ���ض�λ�õ�Ԫ��
int	ClearList(LinkList *L);					//�������������


int main()
{
	LinkList head = NULL;
	ElemType e;
	int boolean;
	CreateList_R(&head,3);

//����ض�λ��Ԫ�ز���

/*	boolean = GetElem(head,2,&e);
	if(boolean == 1)
	{
		printf("name = %s,age = %s",e.name,e.age);
	}
	else if(boolean == 0)
	{
		printf("fail to get");
	}*/

//���ض�λ�ò���Ԫ�ز���

/*	printf("Please input people'name who you want to insert:");
	gets(e.name);
	printf("Please input people'age who you want to insert:");
	gets(e.age);
	boolean = LinkInsert(&head,2,e);
	if(boolean == 1)
	{
		printf("succeed to insert\n");
	}
	else if(boolean == 0)
	{
		printf("fail to insert\n");
	}*/

//���ض�λ��Ԫ��ɾ������

/*	boolean = LinkDelete(&head,2);
	if(boolean == 1)
	{
		printf("succeed to delete\n");
	}
	else if(boolean == 0)
	{
		printf("fail to delete\n");
	}*/

// ������������ղ���

	boolean = ClearList(&head);
	if(boolean == 1)
	{
		printf("succeed to delete\n");
	}
	LinkPrint(head);
	return 0;
}













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
		m++;
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
	m++;
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
	m--;
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