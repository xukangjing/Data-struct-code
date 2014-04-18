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
//�ݹ���ʽ��2-·�鲢�����㷨����
void MSort(int SR[],int TR1[],int s,int t)
{//��SR[s...t]�鲢����ΪTR1[s...t]
	int m;
	int TR2[200];
	if(s==t)
	{
		TR1[s]=SR[s];
	}
	else
	{
		//��SR[s...t]ƽ��ΪSR[s...m]��SR[m...t]
		m=(s+t)/2;
		MSort(SR,TR2,s,m);//�ݹ�Ľ�SR[s...m]�鲢ΪTR2[s...m]
		MSort(SR,TR2,m+1,t);//�ݹ�Ľ�SR[m+1...t]�鲢ΪTR2[m+1...t]
		Merge(TR2,TR1,s,m,t);
	}

}
void MergeSort(SqList &L)
{//�Լ�¼����L.elem[1...n]��2-·�鲢����
	MSort(L.elem,L.elem 1,L.length);
}