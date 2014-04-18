#include "type.h"
#ifndef _SELECT_SORT_H_
#define _SELECT_SORT_H_
//typedef SqList HeapType;
typedef struct
{
     ElemType  *elem;//存储空间基址
	int length;//当前长度
	int listsize;//当前分配的存储长度

} HeapType;
void SelectSort(SqList &L);
int SelectMinKey(SqList L,int i);
void HeapAdjust(HeapType &H,int s,int m);
void HeapSort(HeapType &H);
#endif