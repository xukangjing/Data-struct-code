#include <stdio.h>
#inlcude "All_heads.h"
int Partition_a(SqList &L,int low,int high)
{
	//交换顺序表L中子表L.elem[low...high]的
	//记录，使枢轴记录到位，并返回其所在位置，此时在它之前（后）的位置均不大（小）于它

	int privotkey=L.elem [low];//用子表的第一个记录作为枢轴
	while(low<high)
	{
		//从表的两端交替的向中间扫描
		while (low<high&&L.elem [high]>=privotkey)
		{
			--high;
		}
		swap(L.elem [low],L.elem[high]);//将比枢轴小的记录交换到低端
		while (low<high&&L.elem [low]<=privotkey)
		{
			++low;
		}
		swap(L.elem [low],L.elem[high]);//将比枢轴大的记录交换到高端
	}
	return low;//返回枢轴所在的位置
}
/**
*实际上，在排序的过程中枢轴记录的赋值是多余的，因为只有在一趟排序结束时即low=high的位置时才是枢轴记录的最后位置。
*所以改进算法减少交换的次数，如下
*/
int Partition(SqList &L,int low,int high)
{
	//交换顺序表L中子表L.elem[low...high]的
	//记录，使枢轴记录到位，并返回其所在位置，此时在它之前（后）的位置均不大（小）于它
    L.elem [0]=L.elem [low];
	int privotkey=L.elem [low];//用子表的第一个记录作为枢轴
	while(low<high)
	{
		//从表的两端交替的向中间扫描
		while (low<high&&L.elem [high]>=privotkey)
		{
			--high;
		}
	     L.elem [low ]=L .elem [high];//将比枢轴小的记录移到到低端
		while (low<high&&L.elem [low]<=privotkey)
		{
			++low;
		}
		L .elem [high]=L .elem [low];//将比枢轴大的记录移到到高端
	}
	privotkey=L .elem [0];
	return low;//返回枢轴所在的位置
}
/**
*对顺序表L中的子序列L.elem[low...high]作快速排序
*/
void QSort(SqList &L,int low,int high)
{
	int privotloc;
	if(low<high)//长度大于1
	{
		privotloc=Partition(L,low,high);//将L.elem[low...high]一分为二
		QSort(L,low,privotloc-1);//对低子表递归排序，privotloc是枢轴位置
		QSort(L, privotloc+1,high);//对高子表递归排序，
	}
}
/**
*快速排序
*/
void QuickSort(SqList &L)
{
	QSort(L ,1,L.length);
}