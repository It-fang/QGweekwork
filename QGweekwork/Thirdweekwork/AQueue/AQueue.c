#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"define.h"

void InitAQueue(AQueue *Q)			//初始化队列
{
	int i;
	Q->length = MAXQUEUE;
	Q->front = Q->rear = 0;
}

int LengthAQueue(AQueue *Q)	//确定队列长度
{
	return (Q->rear - Q->front + Q->length) % Q->length;
}

Status IsEmptyAQueue(const AQueue *Q)//检查队列是否为空
{
	return (Q->front == Q->rear?TRUE:FALSE);
}

Status IsFullAQueue(const AQueue *Q)//检查队列是否已满
{
	return (Q->front == ((Q->rear + 1) % Q->length)? TRUE: FALSE);
}

Status EnAQueue(AQueue *Q, void *data)	//入队操作
{
	if(IsFullAQueue(Q))
	{
		printf("队列满了,请等待....");
		return FALSE;
	}
	Q->rear = (Q->rear+1)%Q->length;
	Q->data[Q->rear] = data;
	return TRUE;
}

Status DeAQueue(AQueue *Q)			//出队操作
{
	if(IsFullAQueue(Q))
	{
		printf("队列为空,请先进行排队....");
		return FALSE;
	}
	Q->front = (Q->front+1)%Q->length;
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void **e,int *topdata)	//查看队头元素
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列为空,没有队头.....");
		return FALSE;
	}
	*e = Q->data[Q->rear];
	*topdata = Q->rear;
	return TRUE;
}

Status TraverseAQueue(const AQueue *Q)//遍历函数操作	
{
	int i =0;
	if(IsEmptyAQueue(Q))
	{
		printf("队列为空.....");
		return FALSE;
	}
	i = 1;
	while(i <= ((Q->rear - Q->front + Q->length) % Q->length))
	{
		APrint(Q->data[i+Q->front],datatype[i+Q->front]);
		i = (i+1)%Q->length;
	}
	return TRUE;
}
void APrint(void *q,int datatype)				//打印队列
{
	if (datatype == DOUBLE)
		printf("%lf", *(double *)q);
	if (datatype == CHAR)
		printf("%c", *(char *)q);
	if (datatype == INT)
		printf("%d", *(int *)q);
	if (datatype == STRING)
		printf("%s", *(char *)q);
	printf("-->");
}

Status ClearAQueue(AQueue *Q)			//清空队列
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列已经空了.....");
		return FALSE;
	}
	Q->front = 0;
	Q->rear = 0;
	return TRUE;
}

Status DestoryAQueue(AQueue *Q)			//销毁队列
{
	int i;
	for(i = 0;i < MAXQUEUE;i++)
	{
		free(Q->data[i]);
	}
	return TRUE;
}

void showmenu()
{
	system("cls");
	printf("				--------------------------------------------------\n");
	printf("				|       1.初始化队列             2.队列是否为空    |\n");
	printf("				|       3.入队                   4.出队            |\n");
	printf("				|       5.检测队列长度           6.得到队头元素    |\n");
	printf("				|       7.队列是否已满           8.打印队列        |\n");
	printf("				|       9.清空队列               10.销毁队列       |\n");
	printf("				|                                0.退出            |\n");
	printf("				----------------------------------------------------\n");
}