//����˫�ױ�ʾ��
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
    int  r,n;//����λ�úͽ����
}PTree;
#endif