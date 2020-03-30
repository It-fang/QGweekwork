#ifndef _test_define_
#define _test_define_

#define LEN sizeof(LNode)

typedef struct people
{
	char name[30];
	char age[5];
}ElemType;

typedef	struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, * LinkList;

int m = 0;

#endif