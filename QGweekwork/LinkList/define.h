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

void CreateList_R(LinkList *L,int n);		//初始化并根据后插法创建链表
void LinkPrint(LinkList L);					//打印整个链表
int GetElem(LinkList L,int i,ElemType *e);	//获得特定位置的元素
int LinkInsert(LinkList *L,int i,ElemType e);	//在特定位置插入元素
int LinkDelete(LinkList *L,int i);				//删除特定位置的元素
int	ClearList(LinkList *L);					//将整个链表清空

#endif
