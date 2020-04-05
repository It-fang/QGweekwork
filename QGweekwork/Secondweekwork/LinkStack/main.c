#include<stdio.h>
#include<stdlib.h>
#include"define.h"

int main()
{
	LinkStack s; 
	Status flag;
	Status isInit = ERROR;
	ElemType data;
	int length;
	int select;
	int msg;
	
	while(1)
	{
		showmenu();
		printf("Please input what you want to do :");
		msg = scanf("%d",&select);fflush(stdin);
		printf("\n");
		while(1)
		{
			if(msg != 1)
			{
				printf("input invalid,please again input:");
				msg = scanf("%d",&select);fflush(stdin);
				printf("\n");
			}break;
		}
		system("cls");
		switch(select)
		{
		case 1:{
					if(isInit)
					{
						printf("hava initstack");
						system("pause");
						break;
					}
					flag = initLStack(&s);
					if(flag == SUCCESS)
					{
						printf("initstack success");
						isInit = SUCCESS;
					}
					else
					{
						printf("initstack error");
					}
					system("pause");
			   }break;
		case 2:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					flag = isEmptyLStack(&s);;
					if(flag == SUCCESS)
					{
						printf("the stack is empty");
					}
					else
					{
						printf("the stack isn't empty");
					}
					system("pause");
			   }break;
		case 3:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					printf("please input the data:");
					msg = scanf("%d",&data);fflush(stdin);
					printf("\n");
					while(1)
					{
						if(msg != 1)
						{
							printf("input invalid,please again input:");
							msg = scanf("%d",&data);fflush(stdin);
							printf("\n");
						}break;
					}
					flag = pushLStack(&s,data);
					if(flag == SUCCESS)
					{
						printf("the push data is %d",data);
					}
					else
					{
						printf("push fail");
					}
					system("pause");
			   }break;
		case 4:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					
					flag = popLStack(&s,&data);
					if(flag == SUCCESS)
					{
						printf("the pop data is %d",data);
					}
					else
					{
						printf("pop fail");
					}
					system("pause");
			   }break;
		case 5:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					flag = LStackLength(&s,&length);
					if(flag == SUCCESS)
					{
						printf("the length of stack %d",length);
					}
					system("pause");
			   }break;
		case 6:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					flag = getTopLStack(&s,&data);
					if(flag == SUCCESS)
					{
						printf("the top of data is %d",data);
					}
					else
					{
						printf("get fail");
					}
					system("pause");
			   }break;
		case 7:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					flag = clearLStack(&s);
					if(flag == SUCCESS)
					{
						printf("clear success");
					}
					system("pause");
			   }break;
		case 8:{
					if(!isInit)
					{
						printf("please to initstack");
						system("pause");
						break;
					}
					flag = destroyLStack(&s);
					if(flag == SUCCESS)
					{
						printf("destroy success");
						isInit = ERROR;
					}
					system("pause");
			   }break;

		case 9:{
					exit(0);
			   }break;
		}
	}

}