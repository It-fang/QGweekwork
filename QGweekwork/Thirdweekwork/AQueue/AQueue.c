#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"define.h"

void InitAQueue(AQueue *Q)			//��ʼ������
{
	int i;
	Q->length = MAXQUEUE;
	Q->front = Q->rear = 0;
}

int LengthAQueue(AQueue *Q)	//ȷ�����г���
{
	return (Q->rear - Q->front + Q->length) % Q->length;
}

Status IsEmptyAQueue(const AQueue *Q)//�������Ƿ�Ϊ��
{
	return (Q->front == Q->rear?TRUE:FALSE);
}

Status IsFullAQueue(const AQueue *Q)//�������Ƿ�����
{
	return (Q->front == ((Q->rear + 1) % Q->length)? TRUE: FALSE);
}

Status EnAQueue(AQueue *Q, void *data)	//��Ӳ���
{
	if(IsFullAQueue(Q))
	{
		printf("��������,��ȴ�....");
		return FALSE;
	}
	Q->rear = (Q->rear+1)%Q->length;
	Q->data[Q->rear] = data;
	return TRUE;
}

Status DeAQueue(AQueue *Q)			//���Ӳ���
{
	if(IsFullAQueue(Q))
	{
		printf("����Ϊ��,���Ƚ����Ŷ�....");
		return FALSE;
	}
	Q->front = (Q->front+1)%Q->length;
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void **e,int *topdata)	//�鿴��ͷԪ��
{
	if(IsEmptyAQueue(Q))
	{
		printf("����Ϊ��,û�ж�ͷ.....");
		return FALSE;
	}
	*e = Q->data[Q->rear];
	*topdata = Q->rear;
	return TRUE;
}

Status TraverseAQueue(const AQueue *Q)//������������	
{
	int i =0;
	if(IsEmptyAQueue(Q))
	{
		printf("����Ϊ��.....");
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
void APrint(void *q,int datatype)				//��ӡ����
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

Status ClearAQueue(AQueue *Q)			//��ն���
{
	if(IsEmptyAQueue(Q))
	{
		printf("�����Ѿ�����.....");
		return FALSE;
	}
	Q->front = 0;
	Q->rear = 0;
	return TRUE;
}

Status DestoryAQueue(AQueue *Q)			//���ٶ���
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
	printf("				|       1.��ʼ������             2.�����Ƿ�Ϊ��    |\n");
	printf("				|       3.���                   4.����            |\n");
	printf("				|       5.�����г���           6.�õ���ͷԪ��    |\n");
	printf("				|       7.�����Ƿ�����           8.��ӡ����        |\n");
	printf("				|       9.��ն���               10.���ٶ���       |\n");
	printf("				|                                0.�˳�            |\n");
	printf("				----------------------------------------------------\n");
}