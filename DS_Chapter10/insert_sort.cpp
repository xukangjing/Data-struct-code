#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include " All_heads.h"


/*通过调用ListInsert_Sq()向文件filename中插入数据，然后从文件filename 中格式化读取
数据存储到指定的变量中。*/
Status CreateList_Sq(SqList &L,*FILE filename)
{
	Status InitList_Sq(SqList &L);
	*FILE fp;
	ElemType e;
	if(fp=fopen(filename,"r")==NULL)
	{
		printf("读取文件s%失败",filename);
		exit(0);
	}
	printf("请输入一串数字：以-1为结束标志");
	while(fscanf(fp,"d%",&e)!=EOF)
	{
		ListInsert_Sq(L,2,e);
	}
	fclose(fp);
	return OK;
}
//直接插入排序
void InsertSort(SqList &L)
{
	int i,j;

	for(i=2;i<L.length;i++)
	{
		if(L.elem[i]<L.elem[i-1])
		{
    		L.elem[0]=L.elem[i];//设置哨兵
			for(j=i-1;L.elem[0]<L.elem[j];j--)//寻找插入位置
			{
				L.elem[j+1]=L.elem[j];//凡是大的后移
			}
			L.elem[j+1]=L.elem[0];//插入到正确位置
		}
	}
}
//折半插入排序
void BInsertSort(SqList &L)
{
	int low,high,i,m;
		low=1;high=i-1;
	//对L.length逐个插入
	for(i=2;i<L.length ;i++)
	{
		//将L.elem[i]暂存在L.elem[0]
		L.elem[O]=L.elem[i];
		//在L.[low...high]中进行折半查找插入位置
		
		while (low<=high)
		{
			m=(low+high)/2;
			if(L.elem [i]<L.elem [m])
			{
				//插入点在低半区,缩小所搜区间
				high=m-1;
			}
			else
			{
				low=m+1;
			}
		
		}
		//记录后移
		for(int j=i-1;j>=high+1;j--)
		{
			L.elem [j +1]=L.elem[j];

		}
			//找到插入位置
	L.elem [high+1]=L.elem [0 ];
		
}

/* 我发现如果不知道如何写下一步时：
	
1、画图或举例子，手动描述过程
2、先写出下一步的注释，看着注释再用代码翻译一下即可
3、先分析一趟排序，然后for循环逐个完成Length个
4、总的来说插入排序就是三大步：寻找插入位置--->记录后移----->插入到正确位置
5、在寻找插入位置时采用折半查找法，插入位置在L[high+1]处，
因为若插入位置的数刚好相等也要插入到相等数的后边
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
//希尔排序完整算法
	void ShellSort (SqList &L,int dlta[];int t)
	{
		int k;
		for(k=0;k<t;k++)
		{
			ShellInsert(L,dlta[k]);
		}
	}