#include<stdio.h>

int main()
{
	int i;
	int flag;
	flag = scanf("%d",&i);fflush(stdin);
	while(flag!=1)
	{
		printf("asdf\n");
		flag = scanf("%d",&i);fflush(stdin);
	}
	printf("%d",i);

}