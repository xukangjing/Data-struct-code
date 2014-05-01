//树的双亲表示法
#ifndef _PTREE_H_
#define _PTREE_H_
#define MAX_PTREE_SIZE 100
typedef struct PTNode
{
	TElemType data;
	int parent;
}PTNode;
typedef struct 
{
	PTNode nodes[MAX_PTREE_SIZE]
    int  r,n;//根的位置和结点数
}PTree;
#endif