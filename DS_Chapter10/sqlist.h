#include "type.h"
//定义顺序表的结构和相关算法函数声明
#define OVERFLOW -1
#define LIST_INIT_SIZE 10//线性表容量分配初始容量
#define LISTINCREATMENT 10//线性表存储空间分配增量
#define NOTEXT 0
//定义顺序表结构体SqList
typedef struct
{
	ElemType *elem;//存储空间基址
	int length;//当前长度
	int listsize;//当前分配的存储长度

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
void ShellSort (SqList &L,int dlta[];int t)；