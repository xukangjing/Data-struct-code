#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100//栈的初始值
#define STACKINCREMENT 10//栈容量每次增加的值
typedef int Status;
typedef struct {       //定义链队列
	QueuePtr front;   //队头指针
	QueuePtr rear;	  //队尾指针
}LinkQueue;
#endif 