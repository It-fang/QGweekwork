#include<stdio.h>
#include<stdlib.h>
#include"define.h"

Status initLStack(LinkStack *s)				//��ʼ��ջ
{
	  s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	  if(s->top == NULL)
	  {
		  return ERROR;
	  }
	  s->top->next = NULL;
	  s->count = 0;
	  return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)			//�ж�ջ�Ƿ�Ϊ��
{
	return s->count==0?SUCCESS:ERROR;
}

Status pushLStack(LinkStack *s,ElemType data)			//��ջ
{
	LinkStackPtr Lnew = NULL;
	s->top->data = data;
	Lnew = (LinkStackPtr)malloc(sizeof(StackNode));
	if(Lnew == NULL)
	{
		return ERROR;
	}
	Lnew->next = s->top ;
	s->top = Lnew;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)			//��ջ
{
	LinkStackPtr Lold = s->top->next;
	if(s->count == 0)
	{
		return ERROR;
	}
	*data = Lold->data;
	s->top->next = Lold->next;
	free(Lold);
	s->count--;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)				//�õ�ջ��Ԫ��
{
	if(s->count == 0)
	{
		return ERROR;
	}
	*e = s->top->next->data;
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)		//���ջ����
{
	*length = s->count;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)			//���ջ
{
	LinkStackPtr p1 = s->top;
	LinkStackPtr p2 = s->top;
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	while(p2)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	if(s->top == NULL)
	{
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)				//����ջ
{
	LinkStackPtr p1 = s->top;
	LinkStackPtr p2 = s->top;
	while(p2)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	s->top = NULL;
	s->count = 0;
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


int Priority(char s)
{
	switch(s)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
