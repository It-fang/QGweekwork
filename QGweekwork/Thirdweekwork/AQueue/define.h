#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#define MAXQUEUE 10
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;
typedef int size_t;
typedef enum
{
    FALSE=0, TRUE=1
} Status;

typedef enum
{
	INT = 1,CHAR = 2,DOUBLE = 3,STRING = 4
}Datatype;
Datatype datatype[MAXQUEUE];
void InitAQueue(AQueue *Q);			//��ʼ������
int LengthAQueue(AQueue *Q);	//ȷ�����г���
Status IsEmptyAQueue(const AQueue *Q);//�������Ƿ�Ϊ��
Status IsFullAQueue(const AQueue *Q);//�������Ƿ�����
Status EnAQueue(AQueue *Q, void *data);	//��Ӳ���
Status DeAQueue(AQueue *Q);			//���Ӳ���
Status GetHeadAQueue(AQueue *Q, void *e);	//�鿴��ͷԪ��
Status TraverseAQueue(const AQueue *Q);//������������	
void APrint(void *q,int datatype);				//��ӡ����
Status ClearAQueue(AQueue *Q);	//��ն���
Status DestoryAQueue(AQueue *Q);		//���ٶ���
void showmenu();

#endif 