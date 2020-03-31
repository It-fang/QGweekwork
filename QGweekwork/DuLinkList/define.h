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

void CreateDLinkList_R(DLinkList *L,int n);		//��ʼ�������ݺ�巨��������
void LinkPrint(DLinkList L);						//��ӡ��������
int GetElem(DLinkList L,int i,ElemType *e);	//����ض�λ�õ�Ԫ��
int DLinkInsert(DLinkList *L,int i,ElemType e);	//���ض�λ�ò���Ԫ��
int DLinkDelete(DLinkList *L,int i);				//ɾ���ض�λ�õ�Ԫ��
int	ClearList(DLinkList *L);					//�������������
#endif