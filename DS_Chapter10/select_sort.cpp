#include <stdio.h>
#include "All_heads"



//��L.elem[i...L.length]��ѡ����С�ļ�¼������λ��
int SelectMinKey(SqList L,int i)
{
		L.elem[0]=L.elem [i];
		while (i<L .length &&L .elem [0]<=L .elem [i ])
		{
			i++;
		}
	return i;
}

//��˳�������ѡ������
void SelectSort(SqList &L)
{
	int i,j;
	for(i=1;i<L.length ;i++)
	{
		//��L.elem[i...length]��ѡ����С��ֵ
		j=SelectMinKey(L,i);
		if(i!=j)
		{
			swap(L .elem [i],L .elem [j]);//���i����¼����
		}
	}
}
void HeapAdjust(HeapType &H,int s,int m)
{
	int rc,j;
	rc=H.elem [s];
	for(j=2*s;j<m;j+=2*s)//��������
	{
		//jΪkey�ϴ��¼���±ꣻ
		if(j<m&&H.elem [j ]<H.elem [j+1])
		{
			j++;
		}
		if (rc >H.elem [j])break;
		H.elem [s]=H .elem [j];
		s=j;//���¼���j=2*sΪ��������j+=2*sΪ���������±�����ͬʱ����ifɸѡ��
	}
	//���ֵ���뵽λ
	H.elem[s]=rc;
}

//�����Ķ���������
void HeapSort(HeapType &H)
{
	int i;
	for(i=H .length/2;i>0;i--)//�����һ�η�Ҷ�ӽڵ㿪ʼֱ��i=1,�������Ͻ��д����󶥶�
	{
		HeapAdjust(H,i,H.length)//����Ϊ�󶥶ѹ���
	}
//����󶥶��Ժ��ѡ����������¼���Ѷ��͵�ǰ�μ�����ļ�¼�����һ����¼������
	for(i=n;i>1;--i)
	{
		swap(H .elem [1],H .elem [i]);
		HeapAdjust(H,1,i-1)//��L.elem[1]����ɸѡ����i�����ٲ���
	}
}