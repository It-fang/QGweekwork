#include<stdio.h>
#include<stdlib.h>
#include"define.h"	
	
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

