#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"define.h"

int main()
{
	LinkStack num,opt;
	ElemType e;
	ElemType data;
	ElemType num0,num1,num2;
	char str[100] = {0};
	int i = 0,tmp =0,j;
	int n = 0;
	if((!initLStack(&num))||(!initLStack(&opt)))
	{
		printf("InitStack Fail");
		exit(0);
	}
	printf("Please input operation: ");
	scanf("%s",str);
	while(str[i] !='\0'||isEmptyLStack(&opt) != SUCCESS)
	{
		if(str[i] >= '0' && str[i] <= '9')			//将数字放入栈中
		{
			tmp = tmp * 10 +str[i]-'0';
			i++;
			if(str[i]<'0' || str[i]>'9')
			{
				pushLStack(&num,tmp);
				tmp = 0;
			}
		}
		else
		{
			getTopLStack(&opt,&e);
			if((isEmptyLStack(&opt) == SUCCESS) || (e == '(' && str[i] != ')') || Priority(str[i]) > Priority(e))		//将运算符放入栈中
			{
				pushLStack(&opt,str[i]);
				i++;
				continue;
			}
			if(e == '('&&str[i] == ')')			//出栈不参与运算
			{
				popLStack(&opt,&data);
				i++;
				continue;
			}
			if((str[i] == '\0' && isEmptyLStack(&opt) != SUCCESS) || (str[i] == ')' && e != '(') || Priority(str[i]) <= Priority(e))			//出栈并参与运算
			{
				popLStack(&opt,&data);
				switch(data)
				{
				case '+':{
							popLStack(&num,&num1);
							popLStack(&num,&num2);
							pushLStack(&num,num1+num2);
						 }break;
				case '-':{
							popLStack(&num,&num1);
							popLStack(&num,&num2);
							pushLStack(&num,num2-num1);
						 }break;
				case '*':{
							popLStack(&num,&num1);
							popLStack(&num,&num2);
							pushLStack(&num,num1*num2);
						 }break;
				case '/':{
							popLStack(&num,&num1);
							popLStack(&num,&num2);
							pushLStack(&num,num2/num1);
						 }break;
				}
				continue;
			}
		}
	}
	popLStack(&num,&num0);
	printf("%d",num0);
	return 0;
}