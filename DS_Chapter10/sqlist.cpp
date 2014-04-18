#include <stdio.h>
#include "type.h"
#include "sqlist.h"
#include <stdlib.h>


Status InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//动态分配存储空间
	if(!L.elem)
		exit(OVERFLOW);//存储分配失败
	L.length=0;//空表长度为0
	L.listsize=LIST_INIT_SIZE;//初始存储容量
	return OK;
}
void ListInsert_Sq(SqList &L, int i, ElemType e)
{//在顺序表的第i个位置之前插入元素e
	int j;
	if(i<1||i>L.length+1)return ERROR;
	if(L.length>=L.listsize)
	{
		ElemType *newbase;
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREATMENT)*sizeof(ElemType));//增加分配函数
		if(!newbase)exit(OVERFLOW)//存储分配失败
			L.elem=newbase;//新的基址
		L.listsize+=LISTINCREATMENT;//增加分配
	}//增加分配完毕！

		for(j=L.length;j>=i;j--)
		{
			*(L.elem+j+1)=*(L.elem+j);
		}
		*L.elem[i-1]=e;
		L.length++;//表长加一
}
//销毁线性表
void DestroyList_Sq(SqList &L)
{
	//销毁线性表L
	//要求线性表存在
	free(L.elem);
	L.elem=NULL;
}
//清空线性表
void ClearList_Sq(SqList &L)
{
	//将L重置为空
	//要求线性表存在
	L.length=0;
}
//判断线性表是否为空
Status ListEmpty_Sq(SqList L)
{
	//若为空返回TRUE,否则返回FALSE
	if(0==L.length)
		return TRUE;
	else
		return FALSE;
}
//求L中数据元素的个数
Status ListLength_Sq(SqList L)
{
	//初始条件要求线性表L已经存在
	//返回L中数据元素个数
	return L.length;
}
Status compare_equal_Sq(ElemType e1, ElemType e2)
{
	//判断两个数据元素是否相等，相等返回TRUE，不等返回FALSE
	if(e1 == e2)
		return TRUE;
	else
		return FALSE;
} 

//用e返回L中第i个数据元素的值
void GetElem_Sq(SqList L, int i,ElemType &e)
{
	//要求线性表已经存在，1<=i<=ListLength_Sq(L)
	//用e返回L中第i个数据元素的值
	e=&L.elem[i-1];
}
/Status Compare_equal_Sq(ElemType e1,ElemType e2)
{
	//判读两个数据元素是否相等，相等返回TRUE,不等返回FALSE
	if(e1==e2)
		return TRUE;
	else 
		return FALSE;
}
Status LocateElem_Sq(SqList L,ElemType e,Status * (Compare_equal_Sq)(ElemType e1,ElemType e2))
{
	//线性表已经存在，Compare_Equal_Sq()是数据元素判读函数
    //返回L中第一个与e满足关系Compare_Equal_Sq()的数据元素的位序，若存在返回i,若不存在返回0，
	ElemType *p=L.elem;//定义工作指针
	int i;//定义位序
	for(i=0;i<=L.length-1;i++)
	{
		if(Compare_equal_Sq(e,*(p+i)))
			return i;
	}
	return 0;
}
void ListDlete_Sq(SqList &L,int i,ElemType &e)
{
	//初始条件要求线性表L存在且非空，1<=i<=ListLength_sQ(L)
	//删除第i个元素，并用e返回其值，L的长度减1
     int j;
	 e=*(L.elem+i-1);
	 for(j=i;j<L.length;j++)
	 {
		 *(L.elem +i-1)=*(L.elem +i );//从删除点位置往后依次后后移
	 }
	 L.length --;
}
Status ListTravel_Sq(SqList L,Status *visit(ElemType));
{
	//初始条件要求线性表L已经存在
	//操作结果：依次对L的每个元素调用vist()函数一旦visit失败则操作失败
	int i;
	for(i=1;i<=L.length;j++)
	{
		if(!visit(*(L.elem+i)))
			return FALSE;
	}
	return TRUE;
}
Status visit_display_Sq(ElemTye e)
{
	printf("%d",e);
	return TRUE ;
}
void unionLsit_Sq(SqList &La,SqList Lb)
{
	//将所有在线性表Lb中但是不在线性表La中的元素插入到Lazhong 
	int La_len,Lb_len,i,j;
	ElemType ea,eb;
	La_len=ListLength_Sq(La);
	Lb_len=ListLength_Sq(Lb);
	for(i=1;i<=Lb_len;i++)
	{
		GetElem_Sq(Lb, i,eb);
		for(j=1;j<=La;j++)
		{
		if(	LocateElem_Sq( La, eb, Compare_equal_Sq( ea, eb)))	
			ListInsert_Sq(La,++La_len,eb);
		}
	}
}
//算法2.2按非递减顺序合并链表A、B
void unionLsit_Sq(SqList La,SqList Lb,SqList &Lc)
{
	//已知线性表La和Lb中数据元素按值非递减顺序排列
	//归并La 和Lb得到新的线性表Lc,Lcde 数据元素也按值非递减排列
	InitList_Sq(Lc);
	int i,j,k,ei,ej;
	int La_len,Lb_len;
	La_len=ListLength_Sq(La);
    Lb_len=ListLength_Sq(Lb);
	while ((i<=La_len)&&(j<=Lb_len))
	{
		GetElem_Sq(La,i,ei);
		GetElem_Sq(Lb,j,ej);
		if(ei<=ej)
		{
			ListInsert_Sq(Lc,++k,ei);
			++i;
		}
		else
		{
				ListInsert_Sq(Lc,++k,ej);
			++j;
		}
	}
	while(i<La_len)
	{
		GetElem_Sq(La,i,ei);	
		ListInsert_Sq(Lc,++k,ei);
	}
    while(j<Lb_len)
	{
		GetElem_Sq(Lb,j,ej);	
		ListInsert_Sq(Lc,++k,ej);
	}
}