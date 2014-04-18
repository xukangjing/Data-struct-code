#include <stdio.h>
#include "All_heads.h"
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k;
	for(j=m+1,k=i;j<n&&k<m;k++)
	{
		if(SR[i ]<=SR[j])
		{
			TR [k]=SR [i];
			k++;
		}
		else
		{
			TR [k]=SR [j];
			k++;
		}
	}
	while(i<=m)
	{
		TR [k]=SR [i];
			k++;	
	}
	while (j<=n)
	{
		TR [k]=SR [j];
			k++;
	}
}
//递归形式的2-路归并排序算法如下
void MSort(int SR[],int TR1[],int s,int t)
{//将SR[s...t]归并排序为TR1[s...t]
	int m;
	int TR2[200];
	if(s==t)
	{
		TR1[s]=SR[s];
	}
	else
	{
		//将SR[s...t]平分为SR[s...m]和SR[m...t]
		m=(s+t)/2;
		MSort(SR,TR2,s,m);//递归的将SR[s...m]归并为TR2[s...m]
		MSort(SR,TR2,m+1,t);//递归的将SR[m+1...t]归并为TR2[m+1...t]
		Merge(TR2,TR1,s,m,t);
	}

}
void MergeSort(SqList &L)
{//对记录序列L.elem[1...n]作2-路归并排序
	MSort(L.elem,L.elem 1,L.length);
}