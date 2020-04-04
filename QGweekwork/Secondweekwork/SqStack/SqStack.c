#include<stdio.h>
#include<stdlib.h>
#include"define.h"

Status initStack(SqStack *s,int sizes)			//初始化栈
{
	s->elem = (ElemType *)malloc(sizeof(int)*sizes);
	if(s->elem == NULL)
	{
		return ERROR;
	} 
	else
	{
		s->top = -1;
		s->size = sizes;		//栈的最大容量
		return SUCCESS;
	}
}

Status isEmptyStack(SqStack *s)		//判断栈是否为空
{
	return s->top==-1?SUCCESS:ERROR;
}

Status pushStack(SqStack *s,ElemType data)			//入栈
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


Status popStack(SqStack *s,ElemType *data)			//出栈
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


Status stackLength(SqStack *s,int *length)			//检测栈长度
{
	*length = s->top+1;
	return SUCCESS; 
}


Status getTopStack(SqStack *s,ElemType *e)			 //得到栈顶元素
{
	if(s->top == -1)
		return ERROR;
	else
		*e = s->elem[s->top];
	return SUCCESS;
}

Status clearStack(SqStack *s)			//清空栈
{
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)			//销毁栈
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
	printf("				|       1.初始化栈               2.栈是否为空      |\n");
	printf("				|       3.入栈                   4.出栈            |\n");
	printf("				|       5.检测栈长度             6.得到栈顶元素    |\n");
	printf("				|       7.清空栈                 8.销毁栈          |\n");
	printf("				|                                0.退出            |\n");
	printf("				----------------------------------------------------\n");
}