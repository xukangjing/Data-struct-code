#include "type.h"
//����˳���Ľṹ������㷨��������
#define OVERFLOW -1
#define LIST_INIT_SIZE 10//���Ա����������ʼ����
#define LISTINCREATMENT 10//���Ա�洢�ռ��������
#define NOTEXT 0
//����˳���ṹ��SqList
typedef struct
{
	ElemType *elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢����

} SqList;
Status InitList_Sq(SqList &L);
void DestroyList_Sq(SqList &L);
void ClearList_Sq(SqList &L);
Status ListEmpty_Sq(SqList L);
Status ListLength_Sq(SqList L);
void GetElem_Sq(SqList L, int i,ElemType &e);
Status Compare_equal_Sq(ElemType e1,ElemType e2);
Status LocateElem_Sq(SqList L,ElemType e,Status * Compare_equal_Sq(ElemType,ElemType));
void ListInsert_Sq(SqList &L, int i,ElemType e);
void ListDlete_Sq(SqList &L,int i,ElemType &e);
Status ListTravel_Sq(SqList L,Status *visit(ElemType));
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc);
void unionLsit_Sq(SqList &La,SqList Lb);
void ShellInsert(SqList &L,int dk);
void ShellSort (SqList &L,int dlta[];int t)��