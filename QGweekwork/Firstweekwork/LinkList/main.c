#include<stdio.h>
#include<stdlib.h>
#include"define.h"	

int main()
{
	LinkList head = NULL;
	ElemType e;
	int boolean;
	int select;
	int num;

	while(1)
	{
		Showmenu();
		printf("Please input what you want to do :");
		scanf("%d",&select);
		getchar();
		system("cls");
		switch(select)
		{
		case 1:{
					printf("Please input how much you want to add:");
					scanf("%d",&num);
					getchar();
					boolean = CreateList_R(&head,num);
					if(boolean == 1)
					{
						printf("succeed to create\n");
					}
					else if(boolean == 0)
					{
						printf("Link already exist\n");
					}
					system("pause");
				 }break;
		case 2:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					LinkPrint(head);
					system("pause");
			   }break;
		case 3:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					printf("Please input where you want to get:");
					scanf("%d",&num);
					boolean = GetElem(head,num,&e);
					if(boolean == 1)
					{
						printf("name = %s,age = %s",e.name,e.age);
					}
					else if(boolean == 0)
					{
						printf("fail to get");
					}
					system("pause");
				}break;
		case 4:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					printf("Please input where you want to insert:");
					scanf("%d",&num);
					getchar();
					printf("Please input people'name who you want to insert:");
					gets(e.name);
					printf("Please input people'age who you want to insert:");
					gets(e.age);
					boolean = LinkInsert(&head,num,e);
					if(boolean == 1)
					{
						printf("succeed to insert\n");
					}
					else if(boolean == 0)
					{
						printf("fail to insert\n");
					}
					system("pause");
			   }break;
		case 5:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					printf("Please input where you want to delete:");
					scanf("%d",&num);
					boolean = LinkDelete(&head,num);
					if(boolean == 1)
					{
						printf("succeed to delete\n");
					}
						else if(boolean == 0)
					{
						printf("fail to delete\n");
					}				
					system("pause");
			   }break;
		case 6:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					boolean = ClearList(&head);
					if(boolean == 1)
					{
						printf("succeed to delete\n");
					}
					system("pause");
			   }break;
		case 7:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					Enchange(&head);
					system("pause");
			   }break;
		case 8:{
					if(!head)
					{
						printf("LinkList is inexistence");
						system("pause");
						break;
					}
					FindMidpoint(head,&e);
					printf("name = %s,age = %s",e.name,e.age);
					system("pause");
			   }break;
		case 0:{
					exit(0);
			   }
		}
	}
	
	return 0;
}

