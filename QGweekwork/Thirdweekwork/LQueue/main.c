#include<stdio.h>
#include<stdlib.h>
#include"define.h"
#include<string.h>
int type_f = 0;
int type_r = 0;
int main()
{
	LQueue Q; 
	Status flag;
	Status isInit = FALSE;
	int a;
	char b;
	double c;
	char d[20];
	void *e;
	int length;
	int select;
	int topdata;
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
						printf("hava initQueue");
						system("pause");
						break;
					}
					InitLQueue(&Q);
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
					flag = IsEmptyLQueue(&Q);
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
					type_r++;
					printf("please input the datatype: 1,INT; 2,CHAR; 3,DOUBLE; 4,STRING\n");
					msg = scanf("%d",&datatype[type_r]);fflush(stdin);
					while(1)
					{
						if(msg != 1 || (datatype[type_r]<1 || datatype[type_r]>4))
						{
							printf("input invalid,please again input:");
							msg = scanf("%d",&datatype[type_r]);fflush(stdin);
							printf("\n");
						}break;
					}
					printf("Please input the data :");
					switch(datatype[type_r])
					{
					case INT:{
								scanf("%d",&a);
								flag = EnLQueue(&Q, (void*)&a);
							 }break;
					case CHAR:{
								scanf("%c",&b);
								flag = EnLQueue(&Q, (void*)&b); 
							  }break;
					case DOUBLE:{
								scanf("%lf",&c);
								flag = EnLQueue(&Q, (void*)&c); 
							  }break;
					case STRING:{
								scanf("%s",&d);
								flag = EnLQueue(&Q, (void*)&d); 
							  }break;
					}				
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
					flag = DeLQueue(&Q);
					type_f++;
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
					length = LengthLQueue(&Q);
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
					flag = GetHeadLQueue(&Q, &e);
					if(flag == TRUE)
					{
						LPrint(e,datatype[type_r]);
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
					flag = TraverseLQueue(&Q);		
					system("pause");
			   }break;
		case 8:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = ClearLQueue(&Q);
					if(flag == TRUE)
					{
						printf("clear success");
					}
					system("pause");
			   }
		case 9:{
					if(!isInit)
					{
						printf("please to initQueue");
						system("pause");
						break;
					}
					flag = DestoryLQueue(&Q);
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