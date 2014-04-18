#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include " All_heads.h"


/*ͨ������ListInsert_Sq()���ļ�filename�в������ݣ�Ȼ����ļ�filename �и�ʽ����ȡ
���ݴ洢��ָ���ı����С�*/
Status CreateList_Sq(SqList &L,*FILE filename)
{
	Status InitList_Sq(SqList &L);
	*FILE fp;
	ElemType e;
	if(fp=fopen(filename,"r")==NULL)
	{
		printf("��ȡ�ļ�s%ʧ��",filename);
		exit(0);
	}
	printf("������һ�����֣���-1Ϊ������־");
	while(fscanf(fp,"d%",&e)!=EOF)
	{
		ListInsert_Sq(L,2,e);
	}
	fclose(fp);
	return OK;
}
//ֱ�Ӳ�������
void InsertSort(SqList &L)
{
	int i,j;

	for(i=2;i<L.length;i++)
	{
		if(L.elem[i]<L.elem[i-1])
		{
    		L.elem[0]=L.elem[i];//�����ڱ�
			for(j=i-1;L.elem[0]<L.elem[j];j--)//Ѱ�Ҳ���λ��
			{
				L.elem[j+1]=L.elem[j];//���Ǵ�ĺ���
			}
			L.elem[j+1]=L.elem[0];//���뵽��ȷλ��
		}
	}
}
//�۰��������
void BInsertSort(SqList &L)
{
	int low,high,i,m;
		low=1;high=i-1;
	//��L.length�������
	for(i=2;i<L.length ;i++)
	{
		//��L.elem[i]�ݴ���L.elem[0]
		L.elem[O]=L.elem[i];
		//��L.[low...high]�н����۰���Ҳ���λ��
		
		while (low<=high)
		{
			m=(low+high)/2;
			if(L.elem [i]<L.elem [m])
			{
				//������ڵͰ���,��С��������
				high=m-1;
			}
			else
			{
				low=m+1;
			}
		
		}
		//��¼����
		for(int j=i-1;j>=high+1;j--)
		{
			L.elem [j +1]=L.elem[j];

		}
			//�ҵ�����λ��
	L.elem [high+1]=L.elem [0 ];
		
}

/* �ҷ��������֪�����д��һ��ʱ��
	
1����ͼ������ӣ��ֶ���������
2����д����һ����ע�ͣ�����ע�����ô��뷭��һ�¼���
3���ȷ���һ������Ȼ��forѭ��������Length��
4���ܵ���˵��������������󲽣�Ѱ�Ҳ���λ��--->��¼����----->���뵽��ȷλ��
5����Ѱ�Ҳ���λ��ʱ�����۰���ҷ�������λ����L[high+1]����
��Ϊ������λ�õ����պ����ҲҪ���뵽������ĺ��
*/

	void ShellInsert (SqList &L,int dk)
	{
		int i,j;
		for(i=dk+1;i<L .length ;i++)
		{
				if(L.elem [i]<L.elem [i-dk])
			{
				for(j=i-dk;L.elem [0]<L.elem [j]&&j>0;j-dk)
				{
					L.elem [j+dk]=L.elem [j];
				}
				L .elem [j+dk]=L.elem [0];
			}
		}
	
	}
//ϣ�����������㷨
	void ShellSort (SqList &L,int dlta[];int t)
	{
		int k;
		for(k=0;k<t;k++)
		{
			ShellInsert(L,dlta[k]);
		}
	}