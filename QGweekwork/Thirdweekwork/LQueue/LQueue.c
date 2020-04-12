#include<stdio.h>
#include<stdlib.h>
#include"define.h"
#include<string.h>
extern int type_r;
extern int type_f;
void InitLQueue(LQueue *Q)			//初始化队列
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	Q->length = 0;
}
int LengthLQueue(LQueue *Q)	//确定队列长度
{
	return Q->length;
}
Status IsEmptyLQueue(const LQueue *Q)//检查队列是否为空
{
	return (Q->front == Q->rear? TRUE: FALSE);
}

Status EnLQueue(LQueue *Q, void *data)	//入队操作
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(30);
	memcpy(p->data, data, 30);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue *Q)			//出队操作
{
	Node *p = NULL;
	if(IsEmptyLQueue(Q))
	{
		printf("队列为空,请先进行排队....");
		return FALSE;
	}
	p = Q->front;
	Q->front = Q->front->next;
	Q->length--;
	free(p);
	return TRUE;
}

Status GetHeadLQueue(LQueue *Q, void **e)	//查看队头元素
{
	if(IsEmptyLQueue(Q))
	{
		printf("队列为空,没有队头.....");
		return FALSE;
	}
	*e = Q->rear->data;
	return TRUE;
}

Status TraverseLQueue(const LQueue *Q)		//遍历函数操作	
{
	int i=1;
	Node *p = Q->front->next;
	if(IsEmptyLQueue(Q))
	{
		printf("队列为空.....");
		return FALSE;
	}	
	while(p != NULL)
	{
		LPrint(p->data,datatype[type_f+i]);
		i++;
		p = p->next;
	}
	return TRUE;
}
void LPrint(void *q,int datatype)				//打印队列
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

Status ClearLQueue(LQueue *Q)	//清空队列
{
	Node *p, *q;
	if(IsEmptyLQueue(Q))
	{
		printf("队列已经空了.....");
		return FALSE;
	}
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return TRUE;
}

Status DestoryLQueue(LQueue *Q)		//销毁队列
{
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	return TRUE;
}

void showmenu()
{
	system("cls");
	printf("				--------------------------------------------------\n");
	printf("				|       1.初始化队列             2.队列是否为空    |\n");
	printf("				|       3.入队                   4.出队            |\n");
	printf("				|       5.检测队列长度           6.得到队头元素    |\n");
	printf("				|       7.打印队列               8.清空队列        |\n");
	printf("				|       9.销毁队列               0.退出            |\n");
	printf("				----------------------------------------------------\n");
}
