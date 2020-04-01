#include<stdio.h>
#include<stdlib.h>
#include"define.h"

void CreateDLinkList_R(DLinkList *L,int n)		//初始化并根据后插法创建链表
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

void LinkPrint(DLinkList L)						//打印整个链表
{
	DLinkList p = L->next;
	while(p)
	{
		printf("name = %s,age = %s\n",p->data.name,p->data.age);
		p = p->next ;
	}
}

int GetElem(DLinkList L,int i,ElemType *e)	//获得特定位置的元素
{
	int j = 1;
	DLinkList p = NULL;
	p = L->next;
	while(p && j<i)
	{
		p = p->next ;
		++j;
	}
	if(!p || j>i)			// i值不合法，即i>n或i<0
		return 0;
	*e = p->data;
	return 1;
}

int DLinkInsert(DLinkList *L,int i,ElemType e)	//在特定位置插入元素
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

int DLinkDelete(DLinkList *L,int i)				//删除特定位置的元素
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

int	ClearList(DLinkList *L)				//将整个链表清空
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


void Showmenu()				//打印菜单
{
	system("cls");
	printf("				--------------------------------------------------\n");
	printf("				|       1.创建链表               2.打印链表    |\n");
	printf("				|       3.获得结点               4.增加结点        |\n");
	printf("				|       5.删除结点               6.链表清空        |\n");
	printf("				|                                0.退出系统        |\n");
	printf("				----------------------------------------------------\n");
}