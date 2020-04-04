#include<stdio.h>
#include<stdlib.h>
#include"define.h"

Status initStack(SqStack *s,int sizes)			//��ʼ��ջ
{
	s->elem = (ElemType *)malloc(sizeof(int)*sizes);
	if(s->elem == NULL)
	{
		return ERROR;
	} 
	else
	{
		s->top = -1;
		s->size = sizes;		//ջ���������
		return SUCCESS;
	}
}

Status isEmptyStack(SqStack *s)		//�ж�ջ�Ƿ�Ϊ��
{
	return s->top==-1?SUCCESS:ERROR;
}

Status pushStack(SqStack *s,ElemType data)			//��ջ
{
	if(s->top >= s->size-1)
	{
		return ERROR;
	}
	else
	{
		s->elem[++s->top] = data;
		return SUCCESS;
	}
}


Status popStack(SqStack *s,ElemType *data)			//��ջ
{
	if(s->top == -1)
	{
		return ERROR;
	}
	else
	{
		*data = s->elem[s->top];
		s->top--;
		return SUCCESS;
	}

}


Status stackLength(SqStack *s,int *length)			//���ջ����
{
	*length = s->top+1;
	return SUCCESS; 
}


Status getTopStack(SqStack *s,ElemType *e)			 //�õ�ջ��Ԫ��
{
	if(s->top == -1)
		return ERROR;
	else
		*e = s->elem[s->top];
	return SUCCESS;
}

Status clearStack(SqStack *s)			//���ջ
{
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)			//����ջ
{
	free(s->elem);
	s->top = NULL;
	s->size = NULL;
	return SUCCESS;
}

void showmenu()
{
	system("cls");
	printf("				--------------------------------------------------\n");
	printf("				|       1.��ʼ��ջ               2.ջ�Ƿ�Ϊ��      |\n");
	printf("				|       3.��ջ                   4.��ջ            |\n");
	printf("				|       5.���ջ����             6.�õ�ջ��Ԫ��    |\n");
	printf("				|       7.���ջ                 8.����ջ          |\n");
	printf("				|                                0.�˳�            |\n");
	printf("				----------------------------------------------------\n");
}