#include<stdio.h>
#include<stdlib.h>
#include"define.h"



int CreateList_R(LinkList *L,int n)	//初始化并根据后插法创建链表
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

void LinkPrint(LinkList L)						//打印整个链表
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

int GetElem(LinkList L,int i,ElemType *e)			//获得特定位置的元素
{
	int j = 1;
	LinkList p = NULL;
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

int LinkInsert(LinkList *L,int i,ElemType e)		//在特定位置插入元素
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

int LinkDelete(LinkList *L,int i)				//删除特定位置的元素
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

int	ClearList(LinkList *L)				//将整个链表清空
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


void Showmenu()				//打印菜单
{
	system("cls");
	printf("				--------------------------------------------------\n");
	printf("				|       1.创建链表               2.打印链表        |\n");
	printf("				|       3.获得结点               4.增加结点        |\n");
	printf("				|       5.删除结点               6.链表清空        |\n");
	printf("				|       7.结点奇偶调换           8.快慢指针找中点  |\n");
	printf("				|                                0.退出系统        |\n");
	printf("				----------------------------------------------------\n");
}

void Enchange(LinkList *L)			//将奇偶结点数据域调换
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

void FindMidpoint(LinkList L,ElemType *e)			// 利用快慢指针寻找中点
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
