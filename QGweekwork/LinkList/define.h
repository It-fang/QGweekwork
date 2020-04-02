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


void CreateList_R(LinkList *L,int n);		//��ʼ�������ݺ�巨��������
void LinkPrint(LinkList L);					//��ӡ��������
int GetElem(LinkList L,int i,ElemType *e);	//����ض�λ�õ�Ԫ��
int LinkInsert(LinkList *L,int i,ElemType e);	//���ض�λ�ò���Ԫ��
int LinkDelete(LinkList *L,int i);				//ɾ���ض�λ�õ�Ԫ��
int	ClearList(LinkList *L);					//�������������
void Showmenu()	;		//��ӡ�˵�
void Enchange(LinkList *L);			//����ż������������
void FindMidpoint(LinkList L,ElemType *e);			// ���ÿ���ָ��Ѱ���е�
#endif
