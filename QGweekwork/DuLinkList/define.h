#ifndef _test_define_
#define _test_define_

#define LEN sizeof(DNode)

typedef struct ElemType
{
	char name[30];
	char age[30];
}ElemType;

typedef struct DNode
{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
}DNode,*DLinkList;

int m;

void CreateDLinkList_R(DLinkList *L,int n);		//初始化并根据后插法创建链表
void LinkPrint(DLinkList L);						//打印整个链表
int GetElem(DLinkList L,int i,ElemType *e);	//获得特定位置的元素
int DLinkInsert(DLinkList *L,int i,ElemType e);	//在特定位置插入元素
int DLinkDelete(DLinkList *L,int i);				//删除特定位置的元素
int	ClearList(DLinkList *L);					//将整个链表清空
#endif