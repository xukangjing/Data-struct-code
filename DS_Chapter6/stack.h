#ifndef _STACK_H_
#define _STACK_H_

/* ����˳��ջ */

typedef struct {
	SElemType *base; //��ָ��
	SElemType *top;  //ָ��ջ����ָ��
	int stacksize;   //��ǰջ���������
}SqStack;

Status InitStack (SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType &e);
SElemType GetTop(SqStack S);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
Status StackTraverse(SqStack S, Status (*visit)(SElemType));
Status visit_display(SElemType e);
Status display_char(SElemType e);
#endif