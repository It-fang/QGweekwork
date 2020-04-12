#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
} LQueue;
typedef int size_t;
typedef enum
{
    FALSE=0, TRUE=1
} Status;
typedef enum
{
	INT = 1,CHAR = 2,DOUBLE = 3,STRING = 4
}Datatype;
Datatype datatype[30];


void InitLQueue(LQueue *Q);				//��ʼ������
int LengthLQueue(LQueue *Q);			//ȷ�����г���
Status IsEmptyLQueue(const LQueue *Q);//�������Ƿ�Ϊ��
Status EnLQueue(LQueue *Q, void *data);	//��Ӳ���
Status DeLQueue(LQueue *Q);			//���Ӳ���
Status GetHeadLQueue(LQueue *Q, void **e);	//�鿴��ͷԪ��
Status TraverseLQueue(const LQueue *Q);//������������	
void LPrint(void *q,int datatype);				//��ӡ����
Status ClearLQueue(LQueue *Q);	//��ն���
Status DestoryLQueue(LQueue *Q);		//���ٶ���
void showmenu();

#endif 		