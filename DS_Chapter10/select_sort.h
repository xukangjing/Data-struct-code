#include "type.h"
#ifndef _SELECT_SORT_H_
#define _SELECT_SORT_H_
//typedef SqList HeapType;
typedef struct
{
     ElemType  *elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢����

} HeapType;
void SelectSort(SqList &L);
int SelectMinKey(SqList L,int i);
void HeapAdjust(HeapType &H,int s,int m);
void HeapSort(HeapType &H);
#endif