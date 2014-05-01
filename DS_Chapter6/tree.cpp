#include <stdio.h>
#include <stdlib.h>
#include "All_heads.h"
#include "type.h"
/** 
*�㷨6.4���������������
*/
Status CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(' '==ch)
	{
		return NULL;
	}
	else
	{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		if(!T)
			return ERROR;
		else
		{
			T->data =ch;
			CreateBiTree(T->lchild);
			CreateBiTree(T->rchild);
		}
	
	}
	return;
}
//��ӡһ��Ԫ��
Status Display(TElemType e)
{
	printf("%c",e);
	return OK;
}
/**�򵥵�visit()����
*Status PrintElement (TElemType e)
*{
*/	
}
//�㷨6.1 ������������������ö�������Ĵ洢�ṹ��ÿ��Ԫ�ص���Ӧ�ú���visit()
Status PreOrderTraverse(BiTree T,Status (*visit) (TElemType e))
{
	if(T)
	{
		if(OK==T->data)
			if(OK==PreOrderTraverse(T->lchild),visit)
				if(OK==PreOrderTraverse(T->rchild),visit) return OK;
				return ERROR;
	}
	else
	{
		return OK;
	}
}
//������������������ö�������洢����ÿ��Ԫ�ص��ú���visit;
Status InOrderTraverse(BiTree T,Status (*visit)(TElemType e))
{
	if(T)
	{
		if(InOrderTraverse(T->lchild),visit)
			if(T->data)
				if(InOrderTraverse(T-rchild),visit) return OK;
				return ERROR;
	}
	else
	{
		return OK;
	}
}
//����������������ö�������洢����ÿ��Ԫ�ص��ú���visit();
Status PosterOrderTraverse(BiTree T,Status )
{
	if(T)
	{
		if (PosterOrderTraverse(T->lchild),visit)
			if(PosterOrderTraverse(T->rchild),visit)
				if(T->data) return OK;
				return ERROR;
	}
	else
	{
		return OK;
	}
}
//���ö���ʵ�ֶԶ������Ĳ�α���
Status  LevelOrderTraverse(BiTree T,Status )
{
	BiTree p;
	LinkQueue  Q;
	InitQueue(Q);
	p=T;
	while (p||!QueueEmpty(Q))
	{
		if(p)
		{
			visit(p->data);
			if(p->lchild)
				Enqueue(Q,p->lchild);
			if(p->rchild)
				Enqueue(Q,p->rchild );
			if (!(QueueEmpty(Q)))
				Dequeue(Q,p);
            else
				break;//����Ϊ��ʱ�˳�ѭ��
		}
	}
	return OK;
}
//�ǵݹ鷨 ʵ�ֺ���������������ʼ����зǵݹ�ʵ�����������
Status PosterOrderTraverse2(BiTree T,Status (*visit)(TElemType e) )
{
	SqStack S;
	InitStack(S);
	BiTree p;
	int t=1;
	p=T;
	while (p||!StackEmpty(S ))
	{
		while (p)//�����ߵ���ͷ
		{
			Push(S,p);//��ջ
			p=p->lchild ;//������
			Tag [t++]=0;
		}
		while (!StackEmpty(S)&&1==Tag[t-1])//���Ϊ1��ʾ�������Ѿ����ʹ�
			
		{
			Pop(S,p);
			t--;
			if(ERROR==visit(p->data ))
			{
				return  ERROR;
			}
		��if (!StackEmpty(S)) 
			{
				//������־Ϊ0��������������������������ı�־��Ϊ1
				Tag[t-1]=1;
				GetTop(S ,p);
				p=p->rchild;
			
			}
			else
				break;
		}
		return OK;
}
//�ǵݹ��㷨ʵ���������������
	Status InOrderTraverse2(BiTree T,Status (*visit)(TElemType e))
	{
		SqStack S;
		BiTree p;
		InitStack(S);
		Push(S,T);//��ָ���ջ
		while (!StackEmpty(S))
		{
			while (OK==GetTop(S,p)&& p)//�����ߵ�ͷ
			{
				Push(S,p->lchild);
			}
			Pop(S,p);//��ָ����ջ
			if(!StackEmpty(S))
			{
				Pop(S ,p);
				if(ERROR==visit(p->data ))
				{
					return ERROR;
				}
				Push (S,p->rchild );
			}//if 
		}//while 

          return OK;
		
	}

	//�ǵݹ��㷨ʵ������������������ʼǰ棩
	Status InOrderTraverse3 (BiTree T,Status (*visit)(TElemType e))
	{
	
		BiTree t;
		t=GetTop(T,t);//�ҵ������½��
		while(t)
		{
			visit(t->data );
			if(t->rchild)
				t=GetTop(t->lchild,S);//��t->rchild���������������
			else if (!StackEmpty(S ))
			{
				t=Pop(S );
			}
			else t=NULL;//ջ�ձ����Ѿ�����
		}
		
	}
	//�ǵݹ��㷨ʵ���������������
	Status PreOrderTraverse2(BiTree T,Status (*visit)(TElemType e))
	{
		SqStack S;
		BiTree p;
		InitStack (S);
		p=T;
		while (p||StackEmpty(S))
		{
			if(p)
			{
				//���ʸ�ָ�룬��ָ���ջ
				if(ERROR==visit(p->data ))
					return ERROR;
				Push(S,p);
				p=p->lchild;
			}
			else
			{
				Pop(S,p);
				p=p->rchild ;
			}
		}
		return OK;
	}