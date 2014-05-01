//�����еĻ�������ʵ��
#ifndef _QUEUE_H_
#define -QUEUE_H_
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	//����������
	QueuePtr front;//��ͷָ�룻
	QueuePtr rear;//��βָ��
}LinkQueue;
Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
Status QueueEmpty (LinkQueue &Q);
int  QueueLength (LinkQueue &Q);
Status GetHead (LinkQueue Q,QElemType &e);
Status Enqueue (LinkQueue Q,QElemType &e);
Status Dequeue (LinkQueue Q,QElemType &e);
Status QueueTraverse (LinkQueue Q, Status (*visit)(QElemType &e));
Status visit_display(QElemType &e);