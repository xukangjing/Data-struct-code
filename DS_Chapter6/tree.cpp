#include <stdio.h>
#include <stdlib.h>
#include "All_heads.h"
#include "type.h"
/** 
*算法6.4，按先序构造二叉树
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
//打印一个元素
Status Display(TElemType e)
{
	printf("%c",e);
	return OK;
}
/**简单的visit()函数
*Status PrintElement (TElemType e)
*{
*/	
}
//算法6.1 先序遍历二叉树，采用二叉链表的存储结构对每个元素调用应用函数visit()
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
//中序遍历二叉树，采用二叉链表存储，对每个元素调用函数visit;
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
//后序遍历二叉树采用二叉链表存储，对每个元素调用函数visit();
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
//利用队列实现对二叉树的层次遍历
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
				break;//队列为空时退出循环
		}
	}
	return OK;
}
//非递归法 实现后序遍历二叉树（笔记上有非递归实现中序遍历）
Status PosterOrderTraverse2(BiTree T,Status (*visit)(TElemType e) )
{
	SqStack S;
	InitStack(S);
	BiTree p;
	int t=1;
	p=T;
	while (p||!StackEmpty(S ))
	{
		while (p)//向左走到尽头
		{
			Push(S,p);//进栈
			p=p->lchild ;//向左走
			Tag [t++]=0;
		}
		while (!StackEmpty(S)&&1==Tag[t-1])//结点为1表示右子树已经访问过
			
		{
			Pop(S,p);
			t--;
			if(ERROR==visit(p->data ))
			{
				return  ERROR;
			}
		　if (!StackEmpty(S)) 
			{
				//结束标志为0，则访问右子树，并将右子树的标志改为1
				Tag[t-1]=1;
				GetTop(S ,p);
				p=p->rchild;
			
			}
			else
				break;
		}
		return OK;
}
//非递归算法实现中序遍历二叉树
	Status InOrderTraverse2(BiTree T,Status (*visit)(TElemType e))
	{
		SqStack S;
		BiTree p;
		InitStack(S);
		Push(S,T);//根指针进栈
		while (!StackEmpty(S))
		{
			while (OK==GetTop(S,p)&& p)//向左走到头
			{
				Push(S,p->lchild);
			}
			Pop(S,p);//空指针退栈
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

	//非递归算法实现中序遍历二叉树（笔记版）
	Status InOrderTraverse3 (BiTree T,Status (*visit)(TElemType e))
	{
	
		BiTree t;
		t=GetTop(T,t);//找到最左下结点
		while(t)
		{
			visit(t->data );
			if(t->rchild)
				t=GetTop(t->lchild,S);//把t->rchild看作根结点向左走
			else if (!StackEmpty(S ))
			{
				t=Pop(S );
			}
			else t=NULL;//栈空表明已经结束
		}
		
	}
	//非递归算法实现先序遍历二叉树
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
				//访问根指针，左指针进栈
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