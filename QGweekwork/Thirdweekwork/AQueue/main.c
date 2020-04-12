#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"define.h"
int main()
{
	AQueue Q; 
	Status flag;
	Status isInit = FALSE;
	int a;
	char b;
	double c;
	char d[MAXQUEUE];
	void *e;
	void (*foo)(void *q,int datatype);
	int length;
	int select;
	int topdata;
	int msg;
	int type = 1;

	
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
						printf("hava initQueue");
						system("pause");
						break;
					}
					InitAQueue(&Q);
					printf("initQueue success");
					isInit = TRUE;
					system("pause");
			   }break;
		case 2:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = IsEmptyAQueue(&Q);
					if(flag == TRUE)
					{
						printf("the Queue is empty");
					}
					else
					{
						printf("the Queue isn't empty");
					}
					system("pause");
			   }break;
		case 3:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					printf("please input the datatype: 1,INT; 2,CHAR; 3,DOUBLE; 4,STRING\n");
					msg = scanf("%d",&datatype[type]);fflush(stdin);
					while(1)
					{
						if(msg != 1 || (datatype[type]<1 || datatype[type]>4))
						{
							printf("input invalid,please again input:");
							msg = scanf("%d",&datatype[type]);fflush(stdin);
							printf("\n");
						}break;
					}
					printf("Please input the data :");
					switch(datatype[type])
					{
					case INT:{
								scanf("%d",&a);
								flag = EnAQueue(&Q, (void*)&a);
							 }break;
					case CHAR:{
								scanf("%c",&b);
								flag = EnAQueue(&Q, (void*)&b); 
							  }break;
					case DOUBLE:{
								scanf("%lf",&c);
								flag = EnAQueue(&Q, (void*)&c); 
							  }break;
					case STRING:{
								scanf("%s",&d);
								flag = EnAQueue(&Q, (void*)&d); 
							  }break;
					}
					type = (type + 1)%MAXQUEUE;					
					if(flag == TRUE)
					{
						printf("the Queue push hava successed");
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
						printf("please to initQueue");
						system("pause");
						break;
					}					
					flag = DeAQueue(&Q);
					if(flag == TRUE)
					{
						printf("the Queue pop hava successed");
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
						printf("please to initQueue");
						system("pause");
						break;
					}
					length = LengthAQueue(&Q);
					printf("the length of Queue is %d",length);		
					system("pause");
			   }break;
		case 6:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = GetHeadAQueue(&Q, &e, &topdata);
					if(flag == TRUE)
					{
						APrint(e,datatype[topdata]);
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
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = IsFullAQueue(&Q);
					if(flag == TRUE)
					{
						printf("The Queue is fulled");
					}
					else
					{
						printf("The Queue is not fulled");
					}
					system("pause");
			   }break;
		case 8:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = TraverseAQueue(&Q);		
					system("pause");
			   }break;
		case 9:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = ClearAQueue(&Q);
					if(flag == TRUE)
					{
						printf("clear success");
					}
					system("pause");
			   }
		case 10:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = DestoryAQueue(&Q);
					if(flag == TRUE)
					{
						printf("destory success");
					}
					system("pause");
			   }
		case 0:{
					exit(0);
			   }break;
		}
	}

}