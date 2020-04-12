#include<stdio.h>
#include<stdlib.h>
#include"define.h"
#include<string.h>
extern int type_r;
extern int type_f;
void InitLQueue(LQueue *Q)			//��ʼ������
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	Q->length = 0;
}
int LengthLQueue(LQueue *Q)	//ȷ�����г���
{
	return Q->length;
}
Status IsEmptyLQueue(const LQueue *Q)//�������Ƿ�Ϊ��
{
	return (Q->front == Q->rear? TRUE: FALSE);
}

Status EnLQueue(LQueue *Q, void *data)	//��Ӳ���
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

Status DeLQueue(LQueue *Q)			//���Ӳ���
{
	Node *p = NULL;
	if(IsEmptyLQueue(Q))
	{
		printf("����Ϊ��,���Ƚ����Ŷ�....");
		return FALSE;
	}
	p = Q->front;
	Q->front = Q->front->next;
	Q->length--;
	free(p);
	return TRUE;
}

Status GetHeadLQueue(LQueue *Q, void **e)	//�鿴��ͷԪ��
{
	if(IsEmptyLQueue(Q))
	{
		printf("����Ϊ��,û�ж�ͷ.....");
		return FALSE;
	}
	*e = Q->rear->data;
	return TRUE;
}

Status TraverseLQueue(const LQueue *Q)		//������������	
{
	int i=1;
	Node *p = Q->front->next;
	if(IsEmptyLQueue(Q))
	{
		printf("����Ϊ��.....");
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
void LPrint(void *q,int datatype)				//��ӡ����
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

Status ClearLQueue(LQueue *Q)	//��ն���
{
	Node *p, *q;
	if(IsEmptyLQueue(Q))
	{
		printf("�����Ѿ�����.....");
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

Status DestoryLQueue(LQueue *Q)		//���ٶ���
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
	printf("				|       1.��ʼ������             2.�����Ƿ�Ϊ��    |\n");
	printf("				|       3.���                   4.����            |\n");
	printf("				|       5.�����г���           6.�õ���ͷԪ��    |\n");
	printf("				|       7.��ӡ����               8.��ն���        |\n");
	printf("				|       9.���ٶ���               0.�˳�            |\n");
	printf("				----------------------------------------------------\n");
}
