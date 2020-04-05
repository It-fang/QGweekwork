#include<stdio.h>
#include<stdlib.h>
#include"define.h"

Status initLStack(LinkStack *s)				//初始化栈
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

Status isEmptyLStack(LinkStack *s)			//判断栈是否为空
{
	return s->count==0?SUCCESS:ERROR;
}

Status pushLStack(LinkStack *s,ElemType data)			//入栈
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

Status popLStack(LinkStack *s,ElemType *data)			//出栈
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

Status getTopLStack(LinkStack *s,ElemType *e)				//得到栈顶元素
{
	if(s->count == 0)
	{
		return ERROR;
	}
	*e = s->top->next->data;
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)		//检测栈长度
{
	*length = s->count;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)			//清空栈
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

Status destroyLStack(LinkStack *s)				//销毁栈
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
	printf("				|       1.初始化栈               2.栈是否为空      |\n");
	printf("				|       3.入栈                   4.出栈            |\n");
	printf("				|       5.检测栈长度             6.得到栈顶元素    |\n");
	printf("				|       7.清空栈                 8.销毁栈          |\n");
	printf("				|                                0.退出            |\n");
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
