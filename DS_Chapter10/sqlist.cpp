#include <stdio.h>
#include "type.h"
#include "sqlist.h"
#include <stdlib.h>


Status InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//��̬����洢�ռ�
	if(!L.elem)
		exit(OVERFLOW);//�洢����ʧ��
	L.length=0;//�ձ���Ϊ0
	L.listsize=LIST_INIT_SIZE;//��ʼ�洢����
	return OK;
}
void ListInsert_Sq(SqList &L, int i, ElemType e)
{//��˳���ĵ�i��λ��֮ǰ����Ԫ��e
	int j;
	if(i<1||i>L.length+1)return ERROR;
	if(L.length>=L.listsize)
	{
		ElemType *newbase;
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREATMENT)*sizeof(ElemType));//���ӷ��亯��
		if(!newbase)exit(OVERFLOW)//�洢����ʧ��
			L.elem=newbase;//�µĻ�ַ
		L.listsize+=LISTINCREATMENT;//���ӷ���
	}//���ӷ�����ϣ�

		for(j=L.length;j>=i;j--)
		{
			*(L.elem+j+1)=*(L.elem+j);
		}
		*L.elem[i-1]=e;
		L.length++;//����һ
}
//�������Ա�
void DestroyList_Sq(SqList &L)
{
	//�������Ա�L
	//Ҫ�����Ա����
	free(L.elem);
	L.elem=NULL;
}
//������Ա�
void ClearList_Sq(SqList &L)
{
	//��L����Ϊ��
	//Ҫ�����Ա����
	L.length=0;
}
//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty_Sq(SqList L)
{
	//��Ϊ�շ���TRUE,���򷵻�FALSE
	if(0==L.length)
		return TRUE;
	else
		return FALSE;
}
//��L������Ԫ�صĸ���
Status ListLength_Sq(SqList L)
{
	//��ʼ����Ҫ�����Ա�L�Ѿ�����
	//����L������Ԫ�ظ���
	return L.length;
}
Status compare_equal_Sq(ElemType e1, ElemType e2)
{
	//�ж���������Ԫ���Ƿ���ȣ���ȷ���TRUE�����ȷ���FALSE
	if(e1 == e2)
		return TRUE;
	else
		return FALSE;
} 

//��e����L�е�i������Ԫ�ص�ֵ
void GetElem_Sq(SqList L, int i,ElemType &e)
{
	//Ҫ�����Ա��Ѿ����ڣ�1<=i<=ListLength_Sq(L)
	//��e����L�е�i������Ԫ�ص�ֵ
	e=&L.elem[i-1];
}
/Status Compare_equal_Sq(ElemType e1,ElemType e2)
{
	//�ж���������Ԫ���Ƿ���ȣ���ȷ���TRUE,���ȷ���FALSE
	if(e1==e2)
		return TRUE;
	else 
		return FALSE;
}
Status LocateElem_Sq(SqList L,ElemType e,Status * (Compare_equal_Sq)(ElemType e1,ElemType e2))
{
	//���Ա��Ѿ����ڣ�Compare_Equal_Sq()������Ԫ���ж�����
    //����L�е�һ����e�����ϵCompare_Equal_Sq()������Ԫ�ص�λ�������ڷ���i,�������ڷ���0��
	ElemType *p=L.elem;//���幤��ָ��
	int i;//����λ��
	for(i=0;i<=L.length-1;i++)
	{
		if(Compare_equal_Sq(e,*(p+i)))
			return i;
	}
	return 0;
}
void ListDlete_Sq(SqList &L,int i,ElemType &e)
{
	//��ʼ����Ҫ�����Ա�L�����ҷǿգ�1<=i<=ListLength_sQ(L)
	//ɾ����i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
     int j;
	 e=*(L.elem+i-1);
	 for(j=i;j<L.length;j++)
	 {
		 *(L.elem +i-1)=*(L.elem +i );//��ɾ����λ���������κ����
	 }
	 L.length --;
}
Status ListTravel_Sq(SqList L,Status *visit(ElemType));
{
	//��ʼ����Ҫ�����Ա�L�Ѿ�����
	//������������ζ�L��ÿ��Ԫ�ص���vist()����һ��visitʧ�������ʧ��
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
	//�����������Ա�Lb�е��ǲ������Ա�La�е�Ԫ�ز��뵽Lazhong 
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
//�㷨2.2���ǵݼ�˳��ϲ�����A��B
void unionLsit_Sq(SqList La,SqList Lb,SqList &Lc)
{
	//��֪���Ա�La��Lb������Ԫ�ذ�ֵ�ǵݼ�˳������
	//�鲢La ��Lb�õ��µ����Ա�Lc,Lcde ����Ԫ��Ҳ��ֵ�ǵݼ�����
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