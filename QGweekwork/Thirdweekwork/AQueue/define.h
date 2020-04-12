#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#define MAXQUEUE 10
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
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
void InitAQueue(AQueue *Q);			//初始化队列
int LengthAQueue(AQueue *Q);	//确定队列长度
Status IsEmptyAQueue(const AQueue *Q);//检查队列是否为空
Status IsFullAQueue(const AQueue *Q);//检查队列是否已满
Status EnAQueue(AQueue *Q, void *data);	//入队操作
Status DeAQueue(AQueue *Q);			//出队操作
Status GetHeadAQueue(AQueue *Q, void *e);	//查看队头元素
Status TraverseAQueue(const AQueue *Q);//遍历函数操作	
void APrint(void *q,int datatype);				//打印队列
Status ClearAQueue(AQueue *Q);	//清空队列
Status DestoryAQueue(AQueue *Q);		//销毁队列
void showmenu();

#endif 