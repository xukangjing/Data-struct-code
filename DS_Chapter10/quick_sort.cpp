#include <stdio.h>
#inlcude "All_heads.h"
int Partition_a(SqList &L,int low,int high)
{
	//����˳���L���ӱ�L.elem[low...high]��
	//��¼��ʹ�����¼��λ��������������λ�ã���ʱ����֮ǰ���󣩵�λ�þ�����С������

	int privotkey=L.elem [low];//���ӱ�ĵ�һ����¼��Ϊ����
	while(low<high)
	{
		//�ӱ�����˽�������м�ɨ��
		while (low<high&&L.elem [high]>=privotkey)
		{
			--high;
		}
		swap(L.elem [low],L.elem[high]);//��������С�ļ�¼�������Ͷ�
		while (low<high&&L.elem [low]<=privotkey)
		{
			++low;
		}
		swap(L.elem [low],L.elem[high]);//���������ļ�¼�������߶�
	}
	return low;//�����������ڵ�λ��
}
/**
*ʵ���ϣ�������Ĺ����������¼�ĸ�ֵ�Ƕ���ģ���Ϊֻ����һ���������ʱ��low=high��λ��ʱ���������¼�����λ�á�
*���ԸĽ��㷨���ٽ����Ĵ���������
*/
int Partition(SqList &L,int low,int high)
{
	//����˳���L���ӱ�L.elem[low...high]��
	//��¼��ʹ�����¼��λ��������������λ�ã���ʱ����֮ǰ���󣩵�λ�þ�����С������
    L.elem [0]=L.elem [low];
	int privotkey=L.elem [low];//���ӱ�ĵ�һ����¼��Ϊ����
	while(low<high)
	{
		//�ӱ�����˽�������м�ɨ��
		while (low<high&&L.elem [high]>=privotkey)
		{
			--high;
		}
	     L.elem [low ]=L .elem [high];//��������С�ļ�¼�Ƶ����Ͷ�
		while (low<high&&L.elem [low]<=privotkey)
		{
			++low;
		}
		L .elem [high]=L .elem [low];//���������ļ�¼�Ƶ����߶�
	}
	privotkey=L .elem [0];
	return low;//�����������ڵ�λ��
}
/**
*��˳���L�е�������L.elem[low...high]����������
*/
void QSort(SqList &L,int low,int high)
{
	int privotloc;
	if(low<high)//���ȴ���1
	{
		privotloc=Partition(L,low,high);//��L.elem[low...high]һ��Ϊ��
		QSort(L,low,privotloc-1);//�Ե��ӱ�ݹ�����privotloc������λ��
		QSort(L, privotloc+1,high);//�Ը��ӱ�ݹ�����
	}
}
/**
*��������
*/
void QuickSort(SqList &L)
{
	QSort(L ,1,L.length);
}