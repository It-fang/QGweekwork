#include<stdio.h>
#include<stdlib.h>
#include"define.h"

int main()
{
	DLinkList head = NULL;
	ElemType e;
	int boolean;

	CreateDLinkList_R(&head,3);

//获得特定位置元素测试

/*	boolean = GetElem(head,2,&e);
	if(boolean == 1)
	{
		printf("name = %s,age = %s",e.name,e.age);
	}
	else if(boolean == 0)
	{
		printf("fail to get");
	}*/

//在特定位置插入元素测试

/*	printf("Please input people'name who you want to insert:");
	gets(e.name);
	printf("Please input people'age who you want to insert:");
	gets(e.age);
	boolean = DLinkInsert(&head,2,e);
	if(boolean == 1)
	{
		printf("succeed to insert\n");
	}
	else if(boolean == 0)
	{
		printf("fail to insert\n");
	}*/

//将特定位置元素删除测试

/*	boolean = DLinkDelete(&head,2);
	if(boolean == 1)
	{
		printf("succeed to delete\n");
	}
	else if(boolean == 0)
	{
		printf("fail to delete\n");
	}*/
// 将整个链表清空测试

	boolean = ClearList(&head);
	if(boolean == 1)
	{
		printf("succeed to delete\n");
	}

	LinkPrint(head);

	return 0;
}