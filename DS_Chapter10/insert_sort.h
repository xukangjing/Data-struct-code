// 插入类排序
#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_
#include "type.h"
/* 顺序表和静态链表法*/
//定义链表节点结构体名称
typedef struct  
{
	ElemType data;//数据域
	*ElemType next;//指针域
}LinkNode,*LinkList;
//线性表的动态分配顺序存储结构
typedef struct  
{
	ElemType *elem //存储空间的基址
		int length;//当前顺序表的长度
	int listsize;//当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;
Status CreateSqList(SqList &L,char *filename);;
void InsertSort(SqList &L);
void BInsertSort(SqList &L);
void ShellIsort(SqList &L);
Status CreateLinkList (LinkList &LL,char *filename);
void Swap(int &i,int &j);
void ShellInsert(SqList &L,int dk);
void ShellSort(SqList &L ,int dlta[],int t);
#endif
