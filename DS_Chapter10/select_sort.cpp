#include <stdio.h>
#include "All_heads"



//在L.elem[i...L.length]中选择最小的记录返回其位置
int SelectMinKey(SqList L,int i)
{
		L.elem[0]=L.elem [i];
		while (i<L .length &&L .elem [0]<=L .elem [i ])
		{
			i++;
		}
	return i;
}

//对顺序表作简单选择排序
void SelectSort(SqList &L)
{
	int i,j;
	for(i=1;i<L.length ;i++)
	{
		//在L.elem[i...length]中选择最小的值
		j=SelectMinKey(L,i);
		if(i!=j)
		{
			swap(L .elem [i],L .elem [j]);//与第i个记录交换
		}
	}
}
void HeapAdjust(HeapType &H,int s,int m)
{
	int rc,j;
	rc=H.elem [s];
	for(j=2*s;j<m;j+=2*s)//左右子树
	{
		//j为key较大记录的下标；
		if(j<m&&H.elem [j ]<H.elem [j+1])
		{
			j++;
		}
		if (rc >H.elem [j])break;
		H.elem [s]=H .elem [j];
		s=j;//向下继续j=2*s为左子树，j+=2*s为右子树往下遍历的同时进行if筛选；
	}
	//最大值插入到位
	H.elem[s]=rc;
}

//整个的堆排序如下
void HeapSort(HeapType &H)
{
	int i;
	for(i=H .length/2;i>0;i--)//从最后一课非叶子节点开始直到i=1,由下往上进行创建大顶堆
	{
		HeapAdjust(H,i,H.length)//调整为大顶堆过程
	}
//建完大顶堆以后把选出来的最大记录即堆顶和当前参加排序的记录的最后一个记录交换！
	for(i=n;i>1;--i)
	{
		swap(H .elem [1],H .elem [i]);
		HeapAdjust(H,1,i-1)//对L.elem[1]进行筛选，第i个不再参与
	}
}