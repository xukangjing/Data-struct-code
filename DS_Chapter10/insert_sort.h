// ����������
#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_
#include "type.h"
/* ˳���;�̬����*/
//��������ڵ�ṹ������
typedef struct  
{
	ElemType data;//������
	*ElemType next;//ָ����
}LinkNode,*LinkList;
//���Ա�Ķ�̬����˳��洢�ṹ
typedef struct  
{
	ElemType *elem //�洢�ռ�Ļ�ַ
		int length;//��ǰ˳���ĳ���
	int listsize;//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
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
