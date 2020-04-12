#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
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


void InitLQueue(LQueue *Q);				//初始化队列
int LengthLQueue(LQueue *Q);			//确定队列长度
Status IsEmptyLQueue(const LQueue *Q);//检查队列是否为空
Status EnLQueue(LQueue *Q, void *data);	//入队操作
Status DeLQueue(LQueue *Q);			//出队操作
Status GetHeadLQueue(LQueue *Q, void **e);	//查看队头元素
Status TraverseLQueue(const LQueue *Q);//遍历函数操作	
void LPrint(void *q,int datatype);				//打印队列
Status ClearLQueue(LQueue *Q);	//清空队列
Status DestoryLQueue(LQueue *Q);		//销毁队列
void showmenu();

#endif 		